#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <cstdint>

class Pixel {
private:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
public:
    void multiplyByK(double k);
};

#endif
