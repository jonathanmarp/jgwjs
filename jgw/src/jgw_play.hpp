#include <iostream>
#include <string>
#include <vector>
#include <structure.hpp>
#include <sound.hpp>
#include <fileshelp.hpp>

class JGW_PLAY {
private:
	// function SetStructRefrenchToZero
	void SetStructRefrenchToZero(std::vector<compileSound>& __BUFF__)
	{
		__BUFF__[__BUFF__.size() - 1].S_HZ = 0;
		__BUFF__[__BUFF__.size() - 1].D_DURATION = 0;
	}
private:
	// function PrintDev
	void PrintDev(int& index, double& SSH_Z, float& CCS_Z)
	{
		std::cout << index + 1 << ". " << (double)SSH_Z << "Hz | ";
		std::cout << CCS_Z << "ms" << std::endl;
	}
private:
	// function startMusic
	void StartMusic(std::string nameFile)
	{
		FILESHELP FSH_I(nameFile.c_str());
		switch(FSH_I.itsExist()) {
			case false: {
				std::cout << "Undefined File Name : " << nameFile << std::endl;
			}
			break;
		}

		FSH_I.F_openFile();
		std::vector<compileSound> compilingSoundGet;

		for(int i = 0; i < FSH_I.getVarFile().tellg(); i += 1)
		{
			compileSound _BUFF_;
			FSH_I.getVarFile().seekg(i * sizeof(compileSound));
			FSH_I.getVarFile().read((char*)&_BUFF_, sizeof(compileSound));

			compilingSoundGet.push_back(_BUFF_);
		}

		SetStructRefrenchToZero(compilingSoundGet);

		for(int i = 0; i < compilingSoundGet.size(); i++)
		{
			#ifdef _DEV
				PrintDev(i, compilingSoundGet[i].S_HZ, compilingSoundGet[i].D_DURATION);
			#endif
			sound snd;
			snd.tone((double)compilingSoundGet[i].S_HZ, (int)compilingSoundGet[i].D_DURATION);
		}
		FSH_I.F_closeFile();
	}
public:
	int main(int argc, const char* argv[]) {
		for(int i = 0; i < argc; i++) {
			StartMusic(argv[i]);
		}
		return 0;
	}
};