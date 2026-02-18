#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "pixel.hpp"
#include <vector>

using Filter = std::vector<std::vector<double>>;

class Image
{
private:
    std::vector<std::vector<Pixel>> _data;
    size_t _width;
    size_t _height;

public:
    Image();
    Image(size_t width, size_t height, std::vector<std::vector<Pixel>> data);
    void applyFilter(const Filter& filterMatrix);
};

#endif
