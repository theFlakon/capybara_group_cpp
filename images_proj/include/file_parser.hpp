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
    void parse(const std::string& path, Image& image);
    void output(const std::string& path, Image& image);
    void writePixelsToFile(const std::string& path, Image& image);
};

#endif  // FILE_PARSES_HPP
