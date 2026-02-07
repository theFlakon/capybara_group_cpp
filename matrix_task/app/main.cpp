#include "compressor.h"
#include "decompressor.h"
#include "element.h"

#include <iostream>
#include <vector>

struct MatrixSize
{
    int rows = 0;
    int cols = 0;
};

MatrixSize readSize();
std::vector<Element> readSparseElements();
void printFullMatrix(const std::vector<std::vector<double>>& compressedMatrix);
void printCompressed(const std::vector<Element>& fullMatrix);

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

MatrixSize readSize()
{
    MatrixSize matrixSize;
    std::cout << "Enter size of matrix: <countRow> <countColumn>\n";
    std::cin >> matrixSize.rows >> matrixSize.cols;
    return matrixSize;
}

std::vector<Element> readSparseElements()
{
    int countNotNull = 0;
    std::cout << "Enter count not zero element\n";
    std::cin >> countNotNull;

    std::vector<Element> inputData;

    std::cout << "Enter " << countNotNull
              << " not zero element(s): <cellRow> <cellColumn> <value>\n";

    for(int idx = 0; idx < countNotNull; idx++)
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
        {
            std::cout << row[jdx];
            if(jdx + 1 < row.size())
                std::cout << ' ';
        }
        std::cout << '\n';
    }
}

void printCompressed(const std::vector<Element>& compressedMatrix)
{
    std::cout << "Compressed Matrix:\n";
    for(const auto& e: compressedMatrix)
        std::cout << e.row << ' ' << e.col << ' ' << e.val << '\n';
}
