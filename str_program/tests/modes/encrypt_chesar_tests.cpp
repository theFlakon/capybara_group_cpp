#include "encrypt-chesar.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test chesar encrypt function", "chesarEncrypt")
{
    SECTION("Basic")
    {
        REQUIRE(chesarEncrypt("A", 3) == "D");
        REQUIRE(chesarEncrypt("B", 1) == "C");
        REQUIRE(chesarEncrypt("HELLO", 3) == "KHOOR");
        REQUIRE(chesarEncrypt("hEllo", 3) == "kHoor");
    }

    SECTION("Special")
    {
        REQUIRE(chesarEncrypt("Z", 1) == "A");
        REQUIRE(chesarEncrypt("XyZ", 4) == "BcD");
    }

    SECTION("Large")
    {
        REQUIRE(chesarEncrypt("Hello, world!", 3) == "Khoor, zruog!");
        REQUIRE(chesarEncrypt("ABC", 52) == "ABC");
    }
}
