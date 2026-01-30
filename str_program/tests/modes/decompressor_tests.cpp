#include "decompressor.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test string decompressor function", "decompressor")
{
    SECTION("Basic")
    {
        REQUIRE(deComp("1A") == "A");
        REQUIRE(deComp("2A") == "AA");
        REQUIRE(deComp("3A2B1V") == "AAABBV");
        REQUIRE(deComp("1A1B1C") == "ABC");
    }

    SECTION("Special")
    {
        REQUIRE(deComp("1A1a1A1a") == "AaAa");
        REQUIRE(deComp("2a2b2C") == "aabbCC");
    }

    SECTION("Large")
    {
        REQUIRE(deComp("6A") == "AAAAAA");
        REQUIRE(deComp("10B") == "BBBBBBBBBB");
    }
}
