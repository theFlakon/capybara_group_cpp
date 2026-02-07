#include "decompressor.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test matrix decompressor function", "decompressor")
{
    std::vector<std::vector<double>> matrix1 = {{0, 1}, {1, 0}};
    std::vector<std::vector<double>> matrix2 = {{1, 1}, {1, 0}};
    std::vector<std::vector<double>> matrix3 = {{1, 0}, {0, 1}};


    std::vector<struct Element> compressedMatrix1 = {{0, 1, 1}, {1, 0, 1}}
    std::vector<struct Element> compressedMatrix2 = {{0, 0, 1}, {0, 1, 1}, {1, 0, 1}}
    std::vector<struct Element> compressedMatrix3 = {{0, 0, 1}, {1, 1, 1}}

    SECTION("Basic")
    {
        REQUIRE(decompress(compressedMatrix1) == matrix1);
        REQUIRE(decompress(compressedMatrix2) == matrix2);
        REQUIRE(decompress(compressedMatrix3) == matrix3);
    }
}
