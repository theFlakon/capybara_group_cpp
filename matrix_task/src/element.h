#ifndef ELEMENT_STRUCT_H
#define ELEMENT_STRUCT_H

struct Element {
    int row;
    int col;
    double val;
    Element(int row, int col, double val)
    {
        this->row = row;
        this->col = col;
        this->val = val;
    }
};

#endif