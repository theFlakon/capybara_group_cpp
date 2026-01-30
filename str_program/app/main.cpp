#include <iostream>
#include <cstdlib>
#include <string>

#include "compressor.h"
#include "decompressor.h"
#include "decrypt-chesar.h"
#include "encrypt-chesar.h"

int 
main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " -<MODE(c for compress, d for decompress, dc for chesar decrypt, ec for chesar encrypt)>" 
            << std::endl;

        return EXIT_FAILURE;
    }
    if(strcmp(argv[1], "-c") != 0 && 
        strcmp(argv[1], "-d") != 0 && 
        strcmp(argv[1], "-dc") != 0 && 
        strcmp(argv[1], "-ec") != 0) {
        std::cerr << "Undiefined mode. Use one of these: c for compress, d for decompress, dc for chesar decrypt, ec for chesar encrypt" 
            << std::endl;

        return EXIT_FAILURE;
    }
    std::string input = "";
    std::string result = "";
    std::cout << "Enter your string: ";
    std::cin >> input;
    if(strcmp(argv[1], "-c") == 0) {
        result = compressor(input);
    }
    else if(strcmp(argv[1], "-d") == 0) {
        result = deComp(input);
    }
    else if(strcmp(argv[1], "-dc") == 0) {
        int shift = 0;
        std::cout << "Enter your alpabet shift: ";
        std::cin >> shift;
        result = chesarDecrypt(input, shift);
    }
    else if(strcmp(argv[1], "-ec") == 0) {
        int shift = 0;
        std::cout << "Enter your alpabet shift: ";
        std::cin >> shift;
        result = chesarEncrypt(input, shift);
    }

    std::cout << result << std::endl;

    return EXIT_SUCCESS; 
}
