#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <vector>
#include "element.h"

std::vector<struct Element> compress(const std::vector<std::vector<double>> & matrix);

#endif
