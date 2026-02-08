#include "compressor.h"
#include "element.h"
#include <vector>

std::vector<struct Element>
compress(const std::vector<std::vector<double>>& matrix)
{
    std::vector<struct Element> result{};

    for(size_t i = 0; i < matrix.size(); ++i)
    {
        for(size_t j = 0; j < matrix[i].size(); ++j)
        {
            if(matrix[i][j] == 0)
                continue;

            result.push_back(Element(i, j, matrix[i][j]));
        }
    }
    return result;
}
