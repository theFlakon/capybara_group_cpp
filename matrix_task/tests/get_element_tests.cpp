#include "get_element.h"
#include "matrix.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test get element function", "getElement")
{
    std::vector<struct Element> compressedMatrix1 = {{0, 1, 1}, {1, 0, 1}};
    std::vector<struct Element> compressedMatrix2 = {
        {0, 0, 1}, {0, 1, 1}, {1, 0, 1}};
    std::vector<struct Element> compressedMatrix3 = {{0, 0, 1}, {1, 1, 1}};

    SECTION("Basic")
    {
        REQUIRE(getElement(compressedMatrix1, 2, 2, 0, 1) == 1);
        REQUIRE(getElement(compressedMatrix2, 2, 2, 1, 1) == 0);
        REQUIRE(getElement(compressedMatrix3, 2, 2, 1, 1) == 1);
    }
}
