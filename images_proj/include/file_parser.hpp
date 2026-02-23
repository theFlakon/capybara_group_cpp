#ifndef FILE_PARSER_HPP
#define FILE_PARSER_HPP

#include "image.hpp"

#include <fstream>

class fileParser
{
private:


public:
    void parse(std::ifstream& file, Image& image);

}



#endif