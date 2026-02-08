#include "decompressor.h"
#include "element.h"
#include <vector>

static void
createMatrixRows(const std::vector<struct Element>& compressedMatrix,
                 std::vector<std::vector<double>>& newMatrix, size_t rowsCnt,
                 size_t colsCnt);

static void fillMatrix(const std::vector<struct Element>& compressedMatrix,
                       std::vector<std::vector<double>>& newMatrix,
                       size_t rowsCnt, size_t colsCnt);

std::vector<std::vector<double>>
decompress(const std::vector<struct Element>& compressedMatrix, size_t rowsCnt,
           size_t colsCnt)
{
    std::vector<std::vector<double>> newMatrix{};

    createMatrixRows(compressedMatrix, newMatrix, rowsCnt, colsCnt);
    fillMatrix(compressedMatrix, newMatrix, rowsCnt, colsCnt);

    return newMatrix;
}

void createMatrixRows(const std::vector<struct Element>& compressedMatrix,
                      std::vector<std::vector<double>>& newMatrix,
                      size_t rowsCnt, size_t colsCnt)
{
    for(size_t i = 0; i < rowsCnt; i++)
    {
        std::vector<double> row{};

        for(size_t j = 0; j < colsCnt; j++)
            row.push_back(0.0);

        newMatrix.push_back(row);
    }
}

void fillMatrix(const std::vector<struct Element>& compressedMatrix,
                std::vector<std::vector<double>>& newMatrix, size_t rowsCnt,
                size_t colsCnt)
{
    for(size_t comprMatrixIdx = 0; comprMatrixIdx < compressedMatrix.size();
        ++comprMatrixIdx)
    {
        size_t newRow = compressedMatrix[comprMatrixIdx].row;
        size_t newCol = compressedMatrix[comprMatrixIdx].col;
        double newVal = compressedMatrix[comprMatrixIdx].val;

        bool isRowColValid =
            newRow >= 0 && newCol >= 0 && newRow < rowsCnt && newCol < colsCnt;

        if(isRowColValid)
            newMatrix[newRow][newCol] = newVal;
    }
}
