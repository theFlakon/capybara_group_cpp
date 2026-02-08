#ifndef IO_FUNCS_HPP
#define IO_FUNCS_HPP

#include "matrix.h"

void readSize(Matrix& matrix);
ComprMatrix readSparseElements();
void printFullMatrix(const Matrix& fullMatrix);
void printCompressed(const ComprMatrix& compressedMatrix);

#endif
