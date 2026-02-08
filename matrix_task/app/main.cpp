#include "compressor.h"
#include "decompressor.h"
#include "element.h"
#include "io_funcs.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <vector>

int main()
{
    MatrixSize matrix = readSize();
    std::vector<Element> inputData = readSparseElements();

    std::vector<std::vector<double>> fullMatrix =
        decompress(inputData, matrix.rows, matrix.cols);
    printFullMatrix(fullMatrix);

    std::vector<struct Element> compressMatrix = compress(fullMatrix);
    printCompressed(compressMatrix);

    return EXIT_SUCCESS;
}
