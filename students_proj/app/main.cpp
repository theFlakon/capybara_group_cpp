#include <cstdlib>
#include <fstream>
#include <iostream>
#include "output.hpp"
#include "group.hpp"

int main() {
    std::ifstream input("data.txt");
    if (!input.is_open()) {
        std::cout << "ERROR FILE\n";
        return EXIT_FAILURE;
    }
    Group new_group;
    bool group = makeGroup(input, new_group);

    outputGroupInfo(new_group);
    return EXIT_SUCCESS;
}