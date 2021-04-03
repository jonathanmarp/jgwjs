// script of frequency.hpp
#ifndef _FREQUENCY_HPP
#define _FREQUENCY_HPP
	#ifdef __cplusplus
		#include <map>
	#endif
	#define LengthPolar 60

	// class freq
	class freq {
	private:
		// make variable settings
		bool check; // variable settings check
	public:
		// variable map
		// All variable solfège
		std::map<std::string, std::string> solf;
	public:
		// function boolean parameter
		freq(bool check);
	};
#endif // end of _FREQUENCY_HPP