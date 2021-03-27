#ifndef FREQUENCY_H
#define FREQUENCY_H
#include <map>
#define LengthPolar 60

class freq {
	private:
		bool check;
	public:
		// All variable solfège
		std::map<std::string, std::string> solf;
	public:
		freq(bool check);
};

#endif