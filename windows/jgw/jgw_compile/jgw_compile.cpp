#include <iostream>
#include <fstream>
#include <ios>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#include "getFile.h"

struct compileSound {
	double S_HZ;
	int D_DURATION;
};

const char* expressionToParse = "";

char peek()
{
	return *expressionToParse;
}

char get()
{
	return *expressionToParse++;
}

int expression();

int number()
{
	int result = get() - '0';
	while (peek() >= '0' && peek() <= '9')
	{
		result = 10 * result + get() - '0';
	}
	return result;
}

int factor()
{
	if (peek() >= '0' && peek() <= '9')
		return number();
	else if (peek() == '(')
	{
		get(); // '('
		int result = expression();
		get(); // ')'
		return result;
	}
	else if (peek() == '-')
	{
		get();
		return -factor();
	}
	return 0; // error
}

int term()
{
	int result = factor();
	while (peek() == '*' || peek() == '/')
		if (get() == '*')
			result *= factor();
		else
			result /= factor();
	return result;
}

int expression()
{
	int result = term();
	while (peek() == '+' || peek() == '-')
		if (get() == '+')
			result += term();
		else
			result -= term();
	return result;
}

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string& s)
{
	return rtrim(ltrim(s));
}

void StartCompile(std::string nameFile)
{
	std::string fillFile = getFile(nameFile);
	std::vector<std::string> allCode;
	{
		std::string delimiter = ",";

		size_t pos = 0;
		std::string token;
		while ((pos = fillFile.find(delimiter)) != std::string::npos) {
			token = fillFile.substr(0, pos);
			allCode.push_back(token);
			fillFile.erase(0, pos + delimiter.length());
		}
		allCode.push_back(fillFile);
	}

#define LengthPolar 60

	std::string polar[LengthPolar] = {
		// Notes Array
		"Do1", "Re1", "Mi1",
		"Fa1", "So1", "La1",
		"Si1",
		"Do2", "Re2", "Mi2",
		"Fa2", "So2", "La2",
		"Si2",
		"Do3", "Re3", "Mi3",
		"Fa3", "So3", "La3",
		"Si3",
		"Do4", "Re4", "Mi4",
		"Fa4", "So4", "La4",
		"Si4",
		"Do5", "Re5", "Mi5",
		"Fa5", "So5", "La5",
		"Si5",

		// Keys Array
		"K1_1", "K1_2", "K1_3",
		"K1_4", "K1_5",
		"K2_1", "K2_2", "K2_3",
		"K2_4", "K2_5",
		"K3_1", "K3_2", "K3_3",
		"K3_4", "K3_5",
		"K4_1", "K4_2", "K4_3",
		"K4_4", "K4_5",
		"K5_1", "K5_2", "K5_3",
		"K5_4", "K5_5",
	};

	std::string allFreq[LengthPolar] = {
		// Notes Array
		"65.406", "73.416", "82.407",
		"87.307", "97.999", "110.00",
		"123.47",
		"130.81", "146.83", "164.81",
		"174.61", "196.00", "220.00",
		"246.94",
		"261.63", "293.66", "329.63",
		"349.23", "392.00", "440.00",
		"493.88",
		"523.25", "587.33", "659.26",
		"698.46", "783.99", "880.00",
		"987.77",
		"1046.5", "1174.7", "1318.5",
		"1396.9", "1568.0", "1760.0",
		"1975.5",

		// Keys Array
		"69.296", "77.782", "92.499",
		"103.83", "116.54",
		"138.59", "155.56", "185.00",
		"207.65", "233.08",
		"277.18", "311.13", "369.99",
		"415.30", "466.16",
		"554.37", "622.25", "739.99",
		"830.61", "932.33",
		"1108.7", "1244.5", "1480.0",
		"1661.2", "1864.7"
	};

	for (int i = 0; i < allCode.size(); i += 2)
	{
		allCode[i] = trim(allCode[i]);
		std::vector<std::string> delimitu;
		std::string delimiter = " ";

		size_t pos = 0;
		std::string token;
		while ((pos = allCode[i].find(delimiter)) != std::string::npos) {
			token = allCode[i].substr(0, pos);
			delimitu.push_back(token);
			allCode[i].erase(0, pos + delimiter.length());
		}
		delimitu.push_back(allCode[i]);

		int sizelength = delimitu.size();
		for (int j = 0; j < sizelength; j++)
		{
			for (int k = 0; k < LengthPolar; k++)
			{
				delimitu[j] = trim(delimitu[j]);
				if (delimitu[j] == trim(polar[k]))
				{
					delimitu[j] = allFreq[k];
					break;
				}
			}
		}

		std::string _BUFFER_S = "";
		for (int j = 0; j < delimitu.size(); j++)
		{
			_BUFFER_S += delimitu[j];
		}
		allCode[i] = _BUFFER_S;
	}

	for (int i = 0; i < allCode.size(); i += 2)
	{
		char* cstr = new char[allCode[i].length() + 1];
		strcpy_s(cstr, allCode[i].length() + 1, allCode[i].c_str());
		_strupr_s(cstr, allCode[i].length() + 1);
		expressionToParse = cstr;

		allCode[i] = std::to_string(expression());
	}

	bool itsFirst = false;
	std::vector<compileSound> inCompileSound;
	for (int i = 0; i < allCode.size(); i += 2)
	{
		compileSound cpls;
		cpls.S_HZ = atof(allCode[i].c_str());
		cpls.D_DURATION = atoi(allCode[i + 1].c_str());

		inCompileSound.push_back(cpls);
	}

	std::fstream outputFile;
	outputFile.open(nameFile + ".bnm", std::ios::trunc | std::ios::out | std::ios::binary);
	for (int i = 0; i < inCompileSound.size(); i++)
	{
		outputFile.write((char*)&inCompileSound[i], sizeof(compileSound));
	}
	outputFile.close();
}

int main(int argc, const char* argv[])
{
	if (argc == 1) {
		std::cout << "Give All File Note Music" << std::endl;
	}
	else {
		for (int i = 1; i < argc; i++)
		{
			StartCompile(argv[i]);
		}
	}
	{
		(void)argc;
		(void)argv;
	}
	return 0;
}