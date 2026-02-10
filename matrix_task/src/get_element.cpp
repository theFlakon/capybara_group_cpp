#include "get_element.h"
#include "matrix.h"
#include <iostream>

double getElement(const ComprMatrix& compressedMatrix, size_t rowsCnt,
                  size_t colsCnt, size_t needRow, size_t needCol)
{
    if(needRow >= rowsCnt || needCol >= colsCnt)
    {
        std::cerr << "getElement error: index out of range\n";
        return 0.0;
    }

    for(size_t idx = 0; idx < compressedMatrix.size(); ++idx)
    {
        bool isThisElement = compressedMatrix[idx].row == needRow &&
                             compressedMatrix[idx].col == needCol;

        if(isThisElement)
            return compressedMatrix[idx].val;
    }

    return 0.0;
}
