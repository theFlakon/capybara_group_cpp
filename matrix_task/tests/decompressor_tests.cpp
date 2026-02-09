#include "decompressor.h"
#include "matrix.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test matrix decompressor function", "decompressor")
{
    ComprMatrix compressedMatrix1 = {{0, 1, 1}, {1, 0, 1}};
    ComprMatrix compressedMatrix2 = {
        {0, 0, 1}, {0, 1, 1}, {1, 0, 1}};
    ComprMatrix compressedMatrix3 = {{0, 0, 1}, {1, 1, 1}};

    Matrix expectedMatrix1 = {2, 2, {{0, 1}, {1, 0}}};
    Matrix expectedMatrix2 = {2, 2, {{1, 1}, {1, 0}}};
    Matrix expectedMatrix3 = {2, 2, {{1, 0}, {0, 1}}};

    SECTION("Basic")
    {
        Matrix result1 = {2, 2, {}};
        decompress(compressedMatrix1, result1);
        REQUIRE(result1 == expectedMatrix1);

        Matrix result2 = {2, 2, {}};
        decompress(compressedMatrix2, result2);
        REQUIRE(result2 == expectedMatrix2);

        Matrix result3 = {2, 2, {}};
        decompress(compressedMatrix3, result3);
        REQUIRE(result3 == expectedMatrix3);
    }
}