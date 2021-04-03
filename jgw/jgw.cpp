#include <iostream>
#include <string>
#include <jgw_play.hpp>
#include <jgw_compile.hpp>
#include <jgw_compile_wav.hpp>

int main(int argc, const char* argv[])
{
	// variable args renamed from argv variable
	const char* args[argc - 1];
	// fill empty variable in args array
	for(int i = 1; i < argc; i++) {
		args[i - 2] = argv[i];
	}

	// variable for giving in class
	int argc_args = argc - 2;

	// check argc
	switch(argc) {
		case 1: {
			std::cout << "Giving Parmeter (--play, --compile, --compile-wav) <filepath>" << std::endl;
			return 0;
		}
		break;
		case 2: {
			std::cout << "Giving Parmeter <filepath>" << std::endl;
			return 0;
		}
		break;
	}

	// check
	// if --play
	std::string argvs = argv[1];
	if(argvs == "--play")
	{
		JGW_PLAY jgw_plays;
		jgw_plays.main(argc_args, args);
	} // if --compile
	else if(argvs == "--compile")
	{
		JGW_COMPILE jgw_compile;
		jgw_compile.main(argc_args, args);
	} // --compile-wav
	else if(argvs == "--compile-wav")
	{
		JGW_COMPILE_WAV jgw_compile_wav;
		jgw_compile_wav.main(argc_args, args);
	} // if not exist
	else
	{
		std::cout << "Undefined Parameter 1 : " << argv[1] << std::endl;
	}
	{
		(void)argc;
		(void)argv;
	}
	return 0;
}