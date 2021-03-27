#include <iostream>
#include <string>
#include <ios>
#include <fstream>
#include <vector>
#include "../sound/sound.h"
#include "../getFile/getFile.h"

// struct
struct compileSound {
	double S_HZ;
	float D_DURATION;
};

// function start music
void StartMusic(std::string nameFile);

// function printDev
void PrintDev(int& index, double& SSH_Z, float& CCS_Z);

// function set struct
void SetStructRefrenchToZero(std::vector<compileSound>& __BUFF__);

// function first main
int main(int argc, const char* argv[])
{
	if(argc == 1) {
		std::cout << "Give All File Binary Note Music" << std::endl;
	} else {
		for(int i = 1; i < argc; i++)
		{
			StartMusic(argv[i]);
		}
	}
	{
		(void)argc;
		(void)argv;
	}
	return 0;
}

void SetStructRefrenchToZero(std::vector<compileSound>& __BUFF__)
{
	__BUFF__[__BUFF__.size() - 1].S_HZ = 0;
	__BUFF__[__BUFF__.size() - 1].D_DURATION = 0;
}

void PrintDev(int& index, double& SSH_Z, float& CCS_Z)
{
	std::cout << index + 1 << ". " << (double)SSH_Z << "Hz | ";
	std::cout << CCS_Z << "ms" << std::endl;
}

void StartMusic(std::string nameFile)
{
	std::fstream inputFile;
	inputFile.open(nameFile, std::ios::in | std::ios::binary | std::ios::ate);
	std::vector<compileSound> compilingSoundGet;

	for(int i = 0; i < ((int)inputFile.tellg()); i += 1)
	{
		compileSound _BUFF_;
		inputFile.seekg(i * sizeof(compileSound));
		inputFile.read((char*)&_BUFF_, sizeof(compileSound));

		compilingSoundGet.push_back(_BUFF_);
	}

	SetStructRefrenchToZero(compilingSoundGet);

	for(int i = 0; i < compilingSoundGet.size(); i++)
	{
		#ifdef _DEV
			PrintDev(i, compilingSoundGet[i].S_HZ, compilingSoundGet[i].D_DURATION);
		#endif
		tone((double)compilingSoundGet[i].S_HZ, (float)compilingSoundGet[i].D_DURATION);
	}
	inputFile.close();
}