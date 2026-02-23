#include "image.hpp"

Image::Image() = default;
Image::Image(size_t width, size_t height, std::vector<std::vector<Pixel>> data)
    : _data(std::move(data)), _width(width), _height(height)
{
}

void Image::multSmallMatrix(const Filter& filterMatrix, size_t fstIdx,
                            size_t secIdx)
{
    for(size_t i = 0; i < 3; ++i, ++secIdx)
    {
        size_t fstIdxCpy = fstIdx;

        for(size_t j = 0; j < 3; ++j, ++fstIdxCpy)
            _data[fstIdxCpy][secIdx].multiplyByCoeff(filterMatrix[i][j]);
    }
}

void Image::applyFilter(const Filter& filterMatrix)
{
    for(size_t rowMatrixIdx = 0; rowMatrixIdx < _height / 3; rowMatrixIdx += 3)
    {
        for(size_t columnMatrixIdx = 0; columnMatrixIdx < _width / 3;
            columnMatrixIdx += 3)
        {
            multSmallMatrix(filterMatrix, rowMatrixIdx, columnMatrixIdx);
        }
    }
}
