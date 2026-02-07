#include "decompressor.h"
#include "element.h"
#include <vector>

std::vector<std::vector<double>> decompress(const std::vector<struct Element>& compressedMatrix, size_t rowsCnt, size_t colsCnt)
{
    std::vector<std::vector<double>> newMatrix{};

    for (size_t i = 0; i < rowsCnt; i++)
    {
        std::vector<double> row{};
        for (size_t j = 0; j < colsCnt; j++)
        {
            row.push_back(0.0);
        }
        newMatrix.push_back(row);
    }

    for (size_t i = 0; i < compressedMatrix.size(); ++i)
    {
        size_t newRow = compressedMatrix[i].row;
        size_t newCol = compressedMatrix[i].col;
        double newVal = compressedMatrix[i].val;

        if (newRow >= 0 && newCol >= 0 && newRow < rowsCnt && newCol < colsCnt)
        {
            newMatrix[newRow][newCol] = newVal;
        }
    }

    return newMatrix;
}

