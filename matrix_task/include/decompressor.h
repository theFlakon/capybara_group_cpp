#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include <vector>
#include "element.h"

std::vector<std::vector<double>> decompress(const std::vector<struct Element> & compressedMatrix, size_t row, size_t col);

#endif
