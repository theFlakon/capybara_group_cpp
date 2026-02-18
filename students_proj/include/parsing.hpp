#ifndef PARSING_HPP
#define PARSING_HPP

#include <cstddef>
#include <string>

static bool getNum(size_t& dest, std::string::const_iterator& srcIt,
                   const std::string::const_iterator strEnd);
static bool getWord(std::string& dest, std::string::const_iterator& srcIt,
                    const std::string::const_iterator strEnd);

bool parseRow(std::string& row);

#endif