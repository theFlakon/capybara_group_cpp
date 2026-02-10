#ifndef GETELEMENT_H
#define GETELEMENT_H

#include "matrix.h"

double getElement(const ComprMatrix& compressedMatrix, size_t rowsCnt,
                  size_t colsCnt, size_t needRow, size_t needCol);

#endif
