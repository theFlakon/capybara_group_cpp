#include "matrix.h"
#include <iostream>
#include <vector>

static void readInputElements(ComprMatrix& inputData, size_t countNonZero);

void readSize(Matrix& matrix)
{
    std::cout << "Enter size of matrix: <countRow> <countColumn>\n";
    std::cin >> matrix.rowsCnt >> matrix.colsCnt;
}

ComprMatrix readSparseElements()
{
    int countNonZero = 0;
    std::cout << "Enter count non zero element\n";
    std::cin >> countNonZero;

    std::vector<Element> inputData;

    std::cout << "Enter " << countNonZero
              << " non zero element(s): <cellRow> <cellColumn> <value>\n";

    readInputElements(inputData, countNonZero);

    return inputData;
}

// Static
void readInputElements(ComprMatrix& inputData, size_t countNonZero)
{
    for(int idx = 0; idx < countNonZero; idx++)
    {
        size_t row = 0;
        size_t col = 0;
        double val = 0.0;
        std::cin >> row >> col >> val;
        inputData.push_back({row, col, val});
    }
}

void printFullMatrix(const Matrix& fullMatrix)
{
    std::cout << "Full Matrix:\n";

    for(const auto& row: fullMatrix.data)
    {
        for(size_t jdx = 0; jdx < row.size(); jdx++)
            std::cout << row[jdx] << ' ';

        std::cout << '\n';
    }
}

void printCompressed(const ComprMatrix& compressedMatrix)
{
    std::cout << "Compressed Matrix:\n";
    for(const auto& e: compressedMatrix)
        std::cout << e.row << ' ' << e.col << ' ' << e.val << '\n';
}
