#include "includes.h"
#include "struct.h"
#include "add.h"
#include "prototype.h"

int main(int argc, const char* argv[]) {
    if(argc == 1) {
        std::cout << "Give All File Binary Note Music" << std::endl;
    } else {
        for(int i = 1; i < argc; i++)
        {
            StartConvert(argv[i]);
        }
    }
    {
        (void)argc;
        (void)argv;
    }
    return 0;
}