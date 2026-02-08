#include "element.h"
#include "utils.hpp"
#include <iostream>
#include <vector>

MatrixSize readSize()
{
    MatrixSize matrixSize{};
    std::cout << "Enter size of matrix: <countRow> <countColumn>\n";
    std::cin >> matrixSize.rows >> matrixSize.cols;
    return matrixSize;
}

std::vector<Element> readSparseElements()
{
    int countNonZero = 0;
    std::cout << "Enter count non zero element\n";
    std::cin >> countNonZero;

    std::vector<Element> inputData;

    std::cout << "Enter " << countNonZero
              << " non zero element(s): <cellRow> <cellColumn> <value>\n";

    for(int idx = 0; idx < countNonZero; idx++)
    {
        size_t row = 0;
        size_t col = 0;
        double val = 0.0;
        std::cin >> row >> col >> val;
        inputData.push_back({row, col, val});
    }
    return inputData;
}

void printFullMatrix(const std::vector<std::vector<double>>& fullMatrix)
{
    std::cout << "Full Matrix:\n";

    for(const auto& row: fullMatrix)
    {
        for(size_t jdx = 0; jdx < row.size(); jdx++)
            std::cout << row[jdx] << ' ';

        std::cout << '\n';
    }
}

void printCompressed(const std::vector<Element>& compressedMatrix)
{
    std::cout << "Compressed Matrix:\n";
    for(const auto& e: compressedMatrix)
        std::cout << e.row << ' ' << e.col << ' ' << e.val << '\n';
}
