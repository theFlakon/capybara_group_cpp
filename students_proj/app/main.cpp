#include <fstream>
#include "output.hpp"
#include "group.hpp"

int main() {
    std::ifstream input("data.txt");
    Group newGroup{};
    bool group = makeGroup(input, newGroup);

    outputGroupInfo(newGroup);
    return 1;
}