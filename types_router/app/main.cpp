#include "route.hpp"

#include <string>
#include <vector>

int main () {
    route(42);
    route(3.14159);
    route(std::string("hello"));
    route(std::vector<int>{1,2,3});
    return EXIT_SUCCESS;
}