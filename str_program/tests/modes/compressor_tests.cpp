#include "compressor.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test string compressor function", "compressor")
{
    SECTION("Basic")
    {
        REQUIRE(compressor("A") == "1A");
        REQUIRE(compressor("AA") == "2A");
        REQUIRE(compressor("AAABBV") == "3A2B1V");
        REQUIRE(compressor("ABC") == "1A1B1C");
    }

    SECTION("Special")
    {
        REQUIRE(compressor("AaAa") == "1A1a1A1a");
        REQUIRE(compressor("aabbCC") == "2a2b2C");
    }

    SECTION("Large")
    {
        REQUIRE(compressor("AAAAAA") == "6A");
        REQUIRE(compressor("BBBBBBBBBB") == "10B");
    }
}
