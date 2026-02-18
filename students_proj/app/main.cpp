#include <fstream>
#include "output.hpp"
#include "group.hpp"

int main() {
    std::ifstream input("data.txt");
    Group new_group;
    bool group = makeGroup(input, new_group);

    outputGroupInfo(new_group);
    return 1;
}