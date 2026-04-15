#include <catch2/catch_all.hpp>
#include "text_document.hpp"
#include "spreadsheet_document.hpp"

TEST_CASE("TextDocument returns empty content before open", "[text]") {
    TextDocument doc("hello world");
    REQUIRE(doc.extractContent() == "");
}

TEST_CASE("TextDocument returns content after open", "[text]") {
    TextDocument doc("hello world foo");
    doc.open();
    REQUIRE(doc.extractContent() == "hello world foo");
    REQUIRE(doc.getWordCount() == 3);
}

TEST_CASE("TextDocument format name", "[text]") {
    TextDocument doc("anything");
    REQUIRE(doc.getFormatName() == "TXT");
}

TEST_CASE("SpreadsheetDocument returns empty content before open", "[spreadsheet]") {
    SpreadsheetDocument doc("data.csv");
    REQUIRE(doc.extractContent() == "");
    REQUIRE(doc.getWordCount() == 0);
}