#include <catch2/catch.hpp>
#include "image.hpp"
#include "history_manager.hpp"
#include <cstdint>

TEST_CASE("Pixel multiplication", "pixel") {
    Pixel pixel(100, 150, 200);
    pixel.multiplyByCoeff(0.5);
    REQUIRE(pixel.getRed() == 50);
    REQUIRE(pixel.getGreen() == 75);
    REQUIRE(pixel.getBlue() == 100);
}

TEST_CASE("Filter inversion", "history") {
    HistoryManager hm;
    Filter filter = {
        {2, 0, 0},
        {0, 2, 0},
        {0, 0, 2}
    };
    
    Filter inv = hm.invertFilter(filter);
    REQUIRE(inv[0][0] == Approx(0.5));
    REQUIRE(inv[1][1] == Approx(0.5));
    REQUIRE(inv[2][2] == Approx(0.5));
}

TEST_CASE("History undo", "history") {
    HistoryManager hm;
    
    std::vector<std::vector<Pixel>> data = {
        {Pixel(100, 100, 100), Pixel(100, 100, 100)},
        {Pixel(100, 100, 100), Pixel(100, 100, 100)}
    };
    Image img(2, 2, data);
    
    Filter filter = {
        {0.5, 0, 0},
        {0, 0.5, 0},
        {0, 0, 0.5}
    };
    
    hm.addToHistory(filter);
    img.applyFilter(filter);
    hm.undoAction(img);
}