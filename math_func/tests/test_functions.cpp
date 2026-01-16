#include "../lib/catch_amalgamated.hpp"
#include "../src/functions.cpp"

TEST_CASE("Test power function", "pow") {
    SECTION("Basic") {
        REQUIRE(pow_function(2, 3) == 8);
        REQUIRE(pow_function(3, 4) == 81);
        REQUIRE(pow_function(5, 2) == 25);
        REQUIRE(pow_function(6, 2) == 36);
    }
    
    SECTION("Special") {
        REQUIRE(pow_function(10, 0) == 1);
        REQUIRE(pow_function(0, 5) == 0);
        REQUIRE(pow_function(1, 100) == 1);
    }
    
    SECTION("Large") {
        REQUIRE(pow_function(2, 10) == 1024);
        REQUIRE(pow_function(2, 16) == 65536);
    }
}