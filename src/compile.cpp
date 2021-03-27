#include <iostream>
#include <fstream>
#include <ios>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#include "../getFile/getFile.h"
#include "../frequency/frequency.h"
#include "../loading/loading.h"

// struct
struct compileSound {
	double S_HZ;
	float D_DURATION;
};

// global variable
const char* expressionToParse = "";
const std::string WHITESPACE = " \n\r\t\f\v";

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

// micro
#define LengthPolar 60

// Function For Parser
char peek();
char get();
int expression();
int number();
int factor();
int term();
int expression();

// function for trim
std::string ltrim(const std::string& s);
std::string rtrim(const std::string& s);
std::string trim(const std::string& s);

// function for split
void splitFunctionOne(std::string& fillFile, std::vector<std::string>& allCode, std::string delimiter);

// function start compile
void StartCompile(std::string nameFile);

// function main
int main(int argc, const char* argv[])
{
	if(argc == 1) {
		std::cout << "Give All File Note Music" << std::endl;
	} else {
		for(int i = 1; i < argc; i++)
		{
			StartCompile(argv[i]);
		}
	}
	{
		(void)argc;
		(void)argv;
	}
	loading_I(10);
	return 0;
}

char peek()
{
    return *expressionToParse;
}

char get()
{
    return *expressionToParse++;
}

int number()
{
    int result = get() - '0';
    while (peek() >= '0' && peek() <= '9')
    {
        result = 10*result + get() - '0';
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

void splitFunctionOne(std::string& fillFile, std::vector<std::string>& allCode, std::string delimiter)
{
	size_t pos = 0;
	std::string token;
	while ((pos = fillFile.find(delimiter)) != std::string::npos) {
	    token = fillFile.substr(0, pos);
	    allCode.push_back(token);
	    fillFile.erase(0, pos + delimiter.length());
	}
	allCode.push_back(fillFile);
}

void StartCompile(std::string nameFile)
{
	std::string fillFile = getFile(nameFile);
	std::vector<std::string> allCode;

	splitFunctionOne(fillFile, allCode, ",");

	for(int i = 0; i < allCode.size(); i += 2)
	{
		allCode[i] = trim(allCode[i]);
		std::vector<std::string> delimitu;

		splitFunctionOne(allCode[i], delimitu, " ");

		int sizelength = delimitu.size();
		freq f_FREQS(true);

		for(int j = 0; j < sizelength; j++)
		{
			for(int k = 0; k < LengthPolar; k++)
			{
				delimitu[j] = trim(delimitu[j]);
				if(delimitu[j] == trim(polar[k]))
				{
					#ifdef _DEV
						std::cout << i + 1<< ". " << delimitu[j] << " | " << f_FREQS.solf[polar[k]] << std::endl;
					#endif
					delimitu[j] = f_FREQS.solf[polar[k]];
					break;
				}
			}
		}

		std::string _BUFFER_S = "";
		for(int j = 0; j < delimitu.size(); j++)
		{
			_BUFFER_S += delimitu[j];
		}
		allCode[i] = _BUFFER_S;
	}

	for(int i = 0; i < allCode.size(); i+= 2)
	{
		char *cstr = new char[allCode[i].length() + 1];
		strcpy(cstr, allCode[i].c_str());
		expressionToParse = cstr;

		allCode[i] = std::to_string(expression());
	}

	bool itsFirst = false;
	std::vector<compileSound> inCompileSound;
	for(int i = 0; i < allCode.size(); i += 2)
	{
		compileSound cpls;
		cpls.S_HZ = atof(allCode[i].c_str());
		cpls.D_DURATION = atoi(allCode[i + 1].c_str());

		inCompileSound.push_back(cpls);
	}

	std::fstream outputFile;
	outputFile.open(nameFile + ".bnm", std::ios::trunc | std::ios::out | std::ios::binary);
	for(int i = 0; i < inCompileSound.size(); i++)
	{
		outputFile.write((char*)&inCompileSound[i], sizeof(compileSound));
	}
	outputFile.close();
}