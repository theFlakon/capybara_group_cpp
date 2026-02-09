#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <vector>

typedef std::vector<struct Element> ComprMatrix;

struct Element
{
    size_t row;
    size_t col;
    double val;
    Element(size_t row, size_t col, double val)
    {
        this->row = row;
        this->col = col;
        this->val = val;
    }

    bool operator==(const Element& other) const
    {
        return row == other.row && col == other.col && val == other.val;
    }
};

typedef struct Matrix
{
    size_t rowsCnt;
    size_t colsCnt;
    std::vector<std::vector<double>> data;

    bool operator ==(Matrix& other) const 
    {
        return rowsCnt == other.rowsCnt && colsCnt == other.colsCnt && data == other.data;
    }
} Matrix;

#endif
