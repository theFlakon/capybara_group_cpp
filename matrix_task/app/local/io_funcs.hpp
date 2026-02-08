#ifndef IO_FUNCS_HPP
#define IO_FUNCS_HPP

#include "element.h"
#include "utils.hpp"
#include <vector>

MatrixSize readSize();
std::vector<Element> readSparseElements();
void printFullMatrix(const std::vector<std::vector<double>>& compressedMatrix);
void printCompressed(const std::vector<Element>& fullMatrix);

#endif
