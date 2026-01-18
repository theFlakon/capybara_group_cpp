#include <iostream>
#include <cstdlib>
#include <string>

#include "pow_func.h"

int 
main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <base number> <exp. number>" <<
            std::endl;

        return EXIT_FAILURE;
    }

    long long base_num = std::stoll(argv[1]);
    size_t exp_num = std::stoll(argv[2]);

    std::cout << pow_func(base_num, exp_num) << std::endl;

    return EXIT_SUCCESS; 
}
