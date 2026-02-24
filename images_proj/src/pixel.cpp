#include "pixel.hpp"

Pixel::Pixel(uint8_t red, uint8_t green, uint8_t blue)
    : _red(red), _green(green), _blue(blue)
{
}

void Pixel::multiplyByCoeff(double coeff)
{
    if(coeff < 0.0 || coeff > 1.0)
        return;

    _red = static_cast<uint8_t>(_red * coeff);
    _green = static_cast<uint8_t>(_green * coeff);
    _blue = static_cast<uint8_t>(_blue * coeff);
}
