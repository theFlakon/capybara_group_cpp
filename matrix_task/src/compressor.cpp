#include <vector>
#include "element.h"

std::vector<Element> comress(std::vector<std::vector<double>> input)
{
    std::vector<Element> result;
    for(int i = 0; i < input.size(); i++) {
        for(int j = 0; j < input[i].size(); i++) {
            if(input[i][j] == 0) continue;
            result.push_back(Element(i, j, input[i][j]));
        }
    }
    return result;
}