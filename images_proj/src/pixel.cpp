#include "pixel.hpp"



Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b)
    : _red(r), _green(g), _blue(b) {}

void Pixel::multiplyByCoeff (double coeff) {
    if (coeff < 0.0 || coeff > 1.0) {
        return;
    }

    _red = (uint8_t)(_red * coeff);
    _green = (uint8_t)(_green * coeff);
    _blue = (uint8_t)(_blue * coeff);
}



