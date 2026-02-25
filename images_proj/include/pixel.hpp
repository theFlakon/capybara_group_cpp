#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <cstdint>

class Pixel {
private:
    uint8_t _red;
    uint8_t _green;
    uint8_t _blue;

public:
    Pixel(uint8_t r, uint8_t g, uint8_t b);
    void multiplyByCoeff(double coeff);

    uint8_t getRed() {
        return _red;
    }

    uint8_t getBlue() {
        return _blue;
    }

    uint8_t getGreen() {
        return _green;
    }

};

#endif
