#pragma once
#include <map>
#define LengthPolar 60

class freq {
private:
	bool check;
public:
	// All variable solfège
	std::map<std::string, float> solf;
public:
	freq(bool check);
};