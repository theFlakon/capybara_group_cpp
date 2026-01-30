#include "decrypt-chesar.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test chesar decrypt function", "chesarDecrypt")
{
    SECTION("Basic")
    {
        REQUIRE(chesarDecrypt("D", 3) == "A");
        REQUIRE(chesarDecrypt("C", 1) == "B");
        REQUIRE(chesarDecrypt("KHOOR", 3) == "HELLO");
        REQUIRE(chesarDecrypt("kHoor", 3) == "hEllo");
    }

    SECTION("Special")
    {
        REQUIRE(chesarDecrypt("A", 1) == "Z");
        REQUIRE(chesarDecrypt("BcD", 4) == "XyZ");
    }

    SECTION("Large")
    {
        REQUIRE(chesarDecrypt("ABC", 52) == "ABC");
    }
}
