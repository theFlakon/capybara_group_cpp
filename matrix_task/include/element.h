#ifndef ELEMENT_STRUCT_H
#define ELEMENT_STRUCT_H

#include <cstddef>

struct Element {
    size_t row;
    size_t col;
    double val;
    Element(size_t row, size_t col, double val)
    {
        this->row = row;
        this->col = col;
        this->val = val;
    }

    bool operator==(const Element & other) const {
        return row == other.row && col == other.col && val == other.val;
    }
};

#endif