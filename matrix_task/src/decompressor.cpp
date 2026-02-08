#include "decompressor.h"
#include "matrix.h"
#include <vector>

static void createMatrixRows(const ComprMatrix& compressedMatrix,
                             Matrix& matrix);

static void fillMatrix(const ComprMatrix& compressedMatrix, Matrix& matrix);

void decompress(const ComprMatrix& compressedMatrix, Matrix& matrix)
{
    createMatrixRows(compressedMatrix, matrix);
    fillMatrix(compressedMatrix, matrix);
}

void createMatrixRows(const ComprMatrix& compressedMatrix, Matrix& matrix)
{
    for(size_t i = 0; i < matrix.rowsCnt; i++)
    {
        std::vector<double> row{};

        for(size_t j = 0; j < matrix.colsCnt; j++)
            row.push_back(0.0);

        matrix.data.push_back(row);
    }
}

void fillMatrix(const ComprMatrix& compressedMatrix, Matrix& matrix)
{
    for(size_t comprMatrixIdx = 0; comprMatrixIdx < compressedMatrix.size();
        ++comprMatrixIdx)
    {
        size_t newRow = compressedMatrix[comprMatrixIdx].row;
        size_t newCol = compressedMatrix[comprMatrixIdx].col;
        double newVal = compressedMatrix[comprMatrixIdx].val;

        bool isRowColValid = newRow >= 0 && newCol >= 0 &&
                             newRow < matrix.rowsCnt && newCol < matrix.colsCnt;

        if(isRowColValid)
            matrix.data[newRow][newCol] = newVal;
    }
}
