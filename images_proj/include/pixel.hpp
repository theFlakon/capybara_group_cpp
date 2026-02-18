#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <cstdint>

class Pixel
{
private:
    uint8_t _red;
    uint8_t _green;
    uint8_t _blue;

public:
    void multiplyByCoeff(double coeff);
};

#endif
