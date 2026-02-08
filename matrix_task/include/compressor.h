#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include "element.h"
#include <vector>

std::vector<struct Element>
compress(const std::vector<std::vector<double>>& matrix);

#endif
