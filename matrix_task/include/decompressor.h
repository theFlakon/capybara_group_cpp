#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include <vector>
#include "element.h"

std::vector<std::vector<double>> decompress(const std::vector<Element> & compressedMatrix);

#endif
