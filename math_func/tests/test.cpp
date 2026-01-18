#include <catch2/catch_test_macros.hpp>
#include "pow_func.h"

TEST_CASE("Test power function", "pow") {
    SECTION("Basic") {
        REQUIRE(pow_func(2, 3) == 8);
        REQUIRE(pow_func(3, 4) == 81);
        REQUIRE(pow_func(5, 2) == 25);
        REQUIRE(pow_func(6, 2) == 36);
    }
    
    SECTION("Special") {
        REQUIRE(pow_func(10, 0) == 1);
        REQUIRE(pow_func(0, 5) == 0);
        REQUIRE(pow_func(1, 100) == 1);
    }
    
    SECTION("Large") {
        REQUIRE(pow_func(2, 10) == 1024);
        REQUIRE(pow_func(2, 16) == 65536);
    }
}
