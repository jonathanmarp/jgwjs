#include <iostream>
#include <string>
#include <ios>
#include <fstream>
#include <vector>
#include "../sound/Sound.h"
#include "../getFile/getFile.h"

struct compileSound {
	double S_HZ;
	int D_DURATION;
};

void StartMusic(std::string nameFile)
{
	std::fstream inputFile;
	inputFile.open(nameFile, std::ios::in | std::ios::binary | std::ios::ate);
	std::vector<compileSound> compilingSoundGet;

	for (int i = 0; i < ((int)inputFile.tellg()); i += 1)
	{
		compileSound _BUFF_;
		inputFile.seekg(i * sizeof(compileSound));
		inputFile.read((char*)&_BUFF_, sizeof(compileSound));

		compilingSoundGet.push_back(_BUFF_);
	}

	compilingSoundGet[compilingSoundGet.size() - 1].S_HZ = 0;
	compilingSoundGet[compilingSoundGet.size() - 1].D_DURATION = 0;

	for (int i = 0; i < compilingSoundGet.size(); i++)
	{
		#ifdef _DEV
			std::cout << i + 1 << ". " << (double)compilingSoundGet[i].S_HZ << "Hz | " << (float)compilingSoundGet[i].D_DURATION << "ms" << std::endl;
		#endif
		tone((double)compilingSoundGet[i].S_HZ, (int)compilingSoundGet[i].D_DURATION);
	}
	inputFile.close();
}

int main(int argc, const char* argv[])
{
	if (argc == 1) {
		std::cout << "Give All File Binary Note Music" << std::endl;
	}
	else {
		for (int i = 1; i < argc; i++)
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
