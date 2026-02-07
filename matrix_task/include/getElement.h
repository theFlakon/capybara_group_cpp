#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <iostream>
#include <vector>
#include <element.h>

double getElement(std::vector<struct Element> & compressedMatrix, size_t rowsCnt, size_t colsCnt, size_t needRow, size_t needCol);

#endif