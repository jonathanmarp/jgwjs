#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include "getFile.h"

std::string getFile(std::string nameFile)
{
	std::fstream inputFile;
	std::string _BUFFER_;

	inputFile.open(nameFile, std::ios::in);
	if (!inputFile.is_open())
	{
		return "";
	}

	int indexes = 0;
	while (!inputFile.eof())
	{
		std::string _TEMP_;
		getline(inputFile, _TEMP_);

		if (indexes == 0) {
			_BUFFER_ += _TEMP_;
			indexes += 1;
		}
		else {
			_BUFFER_ += " " + _TEMP_;
		}
	}
	inputFile.close();

	return _BUFFER_;
}