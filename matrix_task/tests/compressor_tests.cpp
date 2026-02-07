#include "compressor.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test matrix compressor function", "compressor")
{
    std::vector<std::vector<double>> matrix1 = {{0, 1}, {1, 0}};
    std::vector<std::vector<double>> matrix2 = {{1, 1}, {1, 0}};
    std::vector<std::vector<double>> matrix3 = {{1, 0}, {0, 1}};


    std::vector<struct Element> compressedMatrix1 = {{0, 1, 1}, {1, 0, 1}}
    std::vector<struct Element> compressedMatrix2 = {{0, 0, 1}, {0, 1, 1}, {1, 0, 1}}
    std::vector<struct Element> compressedMatrix3 = {{0, 0, 1}, {1, 1, 1}}

    SECTION("Basic")
    {
        REQUIRE(compressor(matrix) == compressedMatrix1);
        REQUIRE(compressor(matrix2) == compressedMatrix2);
        REQUIRE(compressor(matrix3) == compressedMatrix3);
    }
}
