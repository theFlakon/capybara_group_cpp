#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "item.hpp"
#include "safe_vector.hpp"

TEST_CASE("Item class tests") {
    SECTION("Setter") {
        Item<int> item(1, 50);
        REQUIRE(item.getId() == 1);
        REQUIRE(item.getValue() == 50);
    }
}

TEST_CASE("SafeVector basic operations") {
    SECTION("Push back and access") {
        SafeVector<int> vec;
        
        vec.pushBack(10);
        REQUIRE(vec.getSize() == 1);
        REQUIRE(vec.getIndex(0) == 10);
    }
}

TEST_CASE("SafeVector move operations") {
    SECTION("Move constructor") {
        SafeVector<int> vec1;
        vec1.pushBack(1);
        vec1.pushBack(2);
        vec1.pushBack(3);
        
        SafeVector<int> vec2(vec1);
        
        REQUIRE(vec2.getSize() == 3);
        REQUIRE(vec2.getIndex(0) == 1);
        REQUIRE(vec2.getIndex(1) == 2);
        REQUIRE(vec2.getIndex(2) == 3);
        
        REQUIRE(vec1.getSize() == 0);
    }
}