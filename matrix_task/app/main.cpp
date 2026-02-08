#include "compressor.h"
#include "decompressor.h"
#include "io_funcs.hpp"
#include "matrix.h"
#include <cstdlib>

int main()
{
    Matrix matrix{};

    readSize(matrix);
    ComprMatrix compressedMatrix = readSparseElements();

    decompress(compressedMatrix, matrix);
    printFullMatrix(matrix);

    ComprMatrix testComprMatrix =
        compress(matrix);  // Just to show the work of this func

    printCompressed(testComprMatrix);

    return EXIT_SUCCESS;
}
