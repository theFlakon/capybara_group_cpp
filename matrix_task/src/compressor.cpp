#include "compressor.h"
#include "element.h"
#include <vector>

std::vector<struct Element> compress(const std::vector<std::vector<double>> & matrix)
{
    std::vector<struct Element> result{};
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++j) {
            if(matrix[i][j] == 0) continue;
            result.push_back(Element(i, j, matrix[i][j]));
        }
    }
    return result;
}