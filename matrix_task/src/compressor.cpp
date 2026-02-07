#include "compressor.h"
#include "element.h"

std::vector<Element> compress(std::vector<std::vector<double>> & matrix)
{
    std::vector<Element> result{};
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++i) {
            if(matrix[i][j] == 0) continue;
            result.push_back(Element(i, j, matrix[i][j]));
        }
    }
    return result;
}