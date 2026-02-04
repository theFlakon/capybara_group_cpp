#include "compressor.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test string compressor function", "compressor")
{
    std::vector<std::vector<double>> matrix1 = {{0, 1}, {1, 0}};
    std::vector<std::vector<double>> matrix2 = {{1, 1}, {1, 0}};
    std::vector<std::vector<double>> matrix3 = {{1, 0}, {0, 1}};

    SECTION("Basic")
    {
        REQUIRE(compressor(matrix) == "");
        REQUIRE(compressor(matrix2) == "");
        REQUIRE(compressor(matrix3) == "");
    }
}
