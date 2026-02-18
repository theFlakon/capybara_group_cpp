#include <catch2/catch_test_macros.hpp>
#include "parsing.hpp"
#include "student.hpp"

TEST_CASE("valid line") {
    std::string row = "768 Podlyagin 15 25 76";
    Student st;

    REQUIRE(parseLine(row, st));
    REQUIRE(st.getId() == 768);
    REQUIRE(st.getSurname() == "Podlyagin");
    REQUIRE(st.getStudentsVec() == std::vector<double>{15, 25, 76});
}

TEST_CASE("valid line with newline") {
    std::string row = "768 Podlyagin 15 25 76\n";
    Student st;

    REQUIRE(parseLine(row, st));
}

TEST_CASE("empty-like line") {
    std::string row = "\n";
    Student st;

    REQUIRE_FALSE(parseLine(row, st));
}

TEST_CASE("invalid id") {
    std::string row = "x Podlyagin 15 25 76";
    Student st;

    REQUIRE_FALSE(parseLine(row, st));
}

TEST_CASE("invalid surname") {
    std::string row = "768 Podlyagin-2 15 25 76";
    Student st;

    REQUIRE_FALSE(parseLine(row, st));
}

TEST_CASE("invalid grade") {
    std::string row = "768 Podlyagin 15 xx 76";
    Student st;

    REQUIRE_FALSE(parseLine(row, st));
}

TEST_CASE("not enough grades") {
    std::string row = "768 Podlyagin 15 25";
    Student st;

    REQUIRE_FALSE(parseLine(row, st));
}
