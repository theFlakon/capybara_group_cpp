#include <catch2/catch_test_macros.hpp>

#include "route.hpp"
#include "type_id.hpp"

#include <string>
#include <vector>

TEST_CASE("type_id compile-time IDs", "[type_id]") {
    CHECK(typeId<int>() == 1);
    CHECK(typeId<double>() == 2);
    CHECK(typeId<std::string>() == 3);
    CHECK(typeId<std::vector<int>>() == 4);
}

TEST_CASE("int: multiplied by 10", "[TypesRouter]") {
    TypesRouter<int> obj(42);
    CHECK(obj.getValue() == 420);
    CHECK(obj.getTypeIdx() == 1);
}

TEST_CASE("double: rounded to 1 decimal", "[TypesRouter]") {
    TypesRouter<double> obj(3.14159);
    CHECK(obj.getValue() == Catch::Approx(3.1));
    CHECK(obj.getTypeIdx() == 2);
}

TEST_CASE("string: uppercased", "[TypesRouter]") {
    TypesRouter<std::string> obj("hello");
    CHECK(obj.getValue() == "HELLO");
    CHECK(obj.getTypeIdx() == 3);
}

TEST_CASE("vector: sum", "[TypesRouter]") {
    TypesRouter<std::vector<int>> obj({1, 2, 3});
    CHECK(obj.getValue()[0] == 6);
    CHECK(obj.getTypeIdx() == 4);
}
