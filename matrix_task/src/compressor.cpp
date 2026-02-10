#include "compressor.h"
#include "matrix.h"
#include <vector>

ComprMatrix compress(const Matrix& matrix)
{
    ComprMatrix result{};

    for(size_t i = 0; i < matrix.colsCnt; ++i)
    {
        for(size_t j = 0; j < matrix.rowsCnt; ++j)
        {
            if(matrix.data[i][j] == 0)
                continue;

            result.push_back(Element(i, j, matrix.data[i][j]));
        }
    }
    return result;
}
