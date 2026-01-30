#include <cstdlib>
#include <iostream>
#include <string>

#include "compressor.h"
#include "decompressor.h"
#include "decrypt-chesar.h"
#include "encrypt-chesar.h"

static std::string parseFlags(const std::string& inputFlag,
                              const std::string& inputString);

int main(int argc, char** argv)
{
    const std::string HELP_MESSAGE =
        "This program allows you to modify your string.\n Syntax: [OPTION] "
        "[STRING]\nAvailable mods and "
        "corresponding flags:\n1. --help:  Prints this message\n2. "
        "-c:  String "
        "compressor\n3. -d:  String decompressor\n4. -ec:  Caesar encrypt\n5. "
        "-dc:  Caesar decrypt\n";

    const std::string INVALID_ARGS_MESSAGE =
        std::string(argv[0]) +
        ": Invalid usage. Type --help for available options.\n";

    if(argc != 3)
    {
        std::cerr << INVALID_ARGS_MESSAGE;

        return EXIT_FAILURE;
    }

    const std::string INPUT_FLAG = argv[1];
    const std::string INPUT_STRING = argv[2];

    std::string result{};

    if(INPUT_FLAG == "--help")
    {
        std::cerr << HELP_MESSAGE;

        return EXIT_SUCCESS;
    }

    try
    {
        result = parseFlags(INPUT_FLAG, INPUT_STRING);

        std::cout << result << std::endl;

        return EXIT_SUCCESS;
    }

    catch(int exception)
    {
        std::cerr << INVALID_ARGS_MESSAGE << std::endl;

        return EXIT_FAILURE;
    }
}

std::string parseFlags(const std::string& inputFlag,
                       const std::string& inputString)
{
    const int ERROR_CODE = -1;

    std::string result{};

    if(inputFlag == "-c")
    {
        result = compressor(inputString);
    }

    else if(inputFlag == "-d")
    {
        result = deComp(inputString);
    }

    else if(inputFlag == "-ec" || inputFlag == "-dc")
    {
        int shift = 0;

        std::cout << "Enter your alpabet shift: ";
        std::cin >> shift;

        if(inputFlag == "-ec")
            result = chesarEncrypt(inputString, shift);

        else
            result = chesarDecrypt(inputString, shift);
    }

    else
    {
        throw ERROR_CODE;
    }

    return result;
}
