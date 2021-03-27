#include <iostream>
#include <string>
#include "../sound/sound.h"

// variable for dev
#ifdef _DEV
	int indexingForDev = 1;
#endif

// function start music
void StartMusic(double S_HZ, float D_DURATION);

// function printDev
void PrintDev(int index, double& SSH_Z, float& CCS_Z);

// function first main
int main(int argc, const char* argv[])
{
	if(argc == 1) {
		std::cout << "Give All Note Music" << std::endl;
	} else {
		for(int i = 1; i < argc; i += 2)
		{
			StartMusic(atof(argv[i]), atof(argv[i+1]));
		}
	}
	{
		(void)argc;
		(void)argv;
	}
	return 0;
}

void PrintDev(int index, double& SSH_Z, float& CCS_Z)
{
	std::cout << index << ". " << (double)SSH_Z << "Hz | ";
	std::cout << CCS_Z << "ms" << std::endl;
}

void StartMusic(double S_HZ, float D_DURATION)
{
	#ifdef _DEV
		PrintDev(indexingForDev++, S_HZ, D_DURATION);
	#endif
	tone(S_HZ, D_DURATION);
}
