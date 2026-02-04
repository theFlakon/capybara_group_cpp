#include "decompressor.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test string decompressor function", "decompressor")
{
    std::vector<std::vector<double>> matrix1 = {{0, 1}, {1, 0}};
    std::vector<std::vector<double>> matrix2 = {{1, 1}, {1, 0}};
    std::vector<std::vector<double>> matrix3 = {{1, 0}, {0, 1}};

    SECTION("Basic")
    {
        REQUIRE(deComp("1A") == matrix1);
        REQUIRE(deComp("2A") == matrix2);
        REQUIRE(deComp("3A2B1V") == matrix3);
    }
}
