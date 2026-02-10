#include "add_sparse.h"
#include "matrix.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test addSparse function", "addSparse")
{
    SECTION("Merge without intersections")
    {
        ComprMatrix a = {{0, 0, 1}, {1, 1, 2}};
        ComprMatrix b = {{0, 1, 3}, {2, 0, 4}};

        ComprMatrix res = addSparse(a, b);

        ComprMatrix expected = {
            {0, 0, 1},
            {0, 1, 3},
            {1, 1, 2},
            {2, 0, 4}
        };

        REQUIRE(res == expected);
    }

    SECTION("Merge with intersections")
    {
        ComprMatrix a = {{0, 0, 1}, {1, 1, 2}};
        ComprMatrix b = {{0, 0, 3}, {2, 2, 4}};

        ComprMatrix res = addSparse(a, b);

        ComprMatrix expected = {
            {0, 0, 4},
            {1, 1, 2},
            {2, 2, 4}
        };

        REQUIRE(res == expected);
    }

    SECTION("Merge with zero")
    {
        ComprMatrix a = {{0, 0, 5}};
        ComprMatrix b = {{0, 0, -5}};

        ComprMatrix res = addSparse(a, b);

        REQUIRE(res.empty());
    }

    SECTION("Merge with empty matrix")
    {
        ComprMatrix a = {{0, 1, 2}, {2, 2, 3}};
        ComprMatrix b = {};

        ComprMatrix res = addSparse(a, b);

        REQUIRE(res == a);
    }

    SECTION("Merge empty matrices")
    {
        ComprMatrix a = {};
        ComprMatrix b = {};

        ComprMatrix res = addSparse(a, b);

        REQUIRE(res.empty());
    }
}
