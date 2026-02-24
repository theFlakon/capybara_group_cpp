#ifndef FILE_PARSER_HPP
#define FILE_PARSER_HPP

#include "image.hpp"
#include <fstream>

class fileParser{
    
public:
    void parse(std::ifstream& file, Image& image);
};

#endif // FILE_PARSES_HPP