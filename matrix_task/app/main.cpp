#include "compressor.h"
#include "decompressor.h"
#include "add_sparse.h"
#include "io_funcs.hpp"
#include "matrix.h"
#include <cstdlib>
#include <string>
#include <iostream>

int main(int argc, char ** argv)

{
    if (argc < 2) {
        std::cout << "ERROR: I need ./program <mode>\n <ap> for add_sparse\n<cm> for comp/decomp\n";
        return EXIT_FAILURE;
    }

    const std::string mode = argv[1];

    if (mode == "cm") {
        Matrix matrix{};

        readSize(matrix);
        ComprMatrix compressedMatrix = readSparseElements();

        decompress(compressedMatrix, matrix);
        printFullMatrix(matrix);

        ComprMatrix testComprMatrix =
            compress(matrix);  // Just to show the work of this func

        printCompressed(testComprMatrix);
    }

    else if (mode == "ap") {
        ComprMatrix cmatrixA = readSparseElements();
        ComprMatrix cmatrixB = readSparseElements();

        sortSparse(cmatrixA); //sort for the alghorithm
        sortSparse(cmatrixB); //sort for the alghorithm

        ComprMatrix resultMatrix = addSparse(cmatrixA, cmatrixB);

        printCompressed(resultMatrix);

    }
    else {
        std::cout << "ERROR: Mode doenst exist\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
