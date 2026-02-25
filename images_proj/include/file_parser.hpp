#ifndef FILE_PARSER_HPP
#define FILE_PARSER_HPP

#include "image.hpp"
#include <fstream>
#include <iostream>

#define CHECK_COND(cond, msg)                                                  \
    do                                                                         \
    {                                                                          \
        if(cond)                                                               \
        {                                                                      \
            std::cerr << msg << "\n";                                          \
            return;                                                            \
        }                                                                      \
    }                                                                          \
    while(0);

class FileParser
{
public:
    void parse(std::ifstream& file, Image& image);
};

#endif  // FILE_PARSES_HPP
