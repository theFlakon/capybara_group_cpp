#ifndef GETELEMENT_H
#define GETELEMENT_H

#include "element.h"
#include <vector>

double getElement(const std::vector<struct Element>& compressedMatrix,
                  size_t rowsCnt, size_t colsCnt, size_t needRow,
                  size_t needCol);

#endif
