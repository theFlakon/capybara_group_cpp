#include "compressor.h"
#include "matrix.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test matrix compressor function", "compressor")
{
    Matrix matrix1 = {2, 2, {{0, 1}, {1, 0}}};
    Matrix matrix2 = {2, 2, {{1, 1}, {1, 0}}};
    Matrix matrix3 = {2, 2, {{1, 0}, {0, 1}}};

    ComprMatrix compressedMatrix1 = {{0, 1, 1}, {1, 0, 1}};
    ComprMatrix compressedMatrix2 = {
        {0, 0, 1}, {0, 1, 1}, {1, 0, 1}};
    ComprMatrix compressedMatrix3 = {{0, 0, 1}, {1, 1, 1}};

    SECTION("Basic")
    {
        REQUIRE(compress(matrix1) == compressedMatrix1);
        REQUIRE(compress(matrix2) == compressedMatrix2);
        REQUIRE(compress(matrix3) == compressedMatrix3);
    }
}
