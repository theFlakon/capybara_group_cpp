#include "RawPayload.hpp"
#include <stdexcept>
#include <utility>

RawPayload::RawPayload(size_t cap)
    : _buffer(new char[cap]), _capacity(cap), _owned(true) {};

RawPayload::~RawPayload()
{
    bool owned = getOwned();
    char* buffer = getBuffer();

    if(owned && buffer != nullptr)
        delete[] _buffer;
}

RawPayload::RawPayload(const RawPayload& other)
    : _buffer(new char[other._capacity]), _capacity(other._capacity),
      _owned(true)
{
    char* buffer = getBuffer();
    const char* newBuffer = other.getBuffer();
    size_t capacity = getCapacity();

    std::memcpy(buffer, newBuffer, capacity);
}

RawPayload& RawPayload::operator=(const RawPayload& other)
{
    if(this == &other)
        return *this;

    size_t newCapacity = other.getCapacity();

    char* newBuffer = new char[newCapacity];

    if(newBuffer == nullptr)
        throw std::runtime_error("Failed to allocate memory");

    std::memcpy(newBuffer, other._buffer, other._capacity);

    bool owned = getOwned();
    char* buffer = getBuffer();

    if(owned && buffer != nullptr)
        delete[] _buffer;

    setBuffer(newBuffer);
    setCapacity(other._capacity);
    setOwned(true);

    return *this;
}

RawPayload::RawPayload(RawPayload&& other) noexcept
    : _buffer(std::exchange(other._buffer, nullptr)),
      _capacity(std::exchange(other._capacity, 0)),
      _owned(std::exchange(other._owned, false))
{
}

void RawPayload::setBuffer(char* buffer)
{
    _buffer = buffer;
}

void RawPayload::setCapacity(size_t capacity)
{
    _capacity = capacity;
}

void RawPayload::setOwned(bool owned)
{
    _owned = owned;
}

char* RawPayload::getBuffer()
{
    return _buffer;
}
const char* RawPayload::getBuffer() const
{
    return _buffer;
}

size_t RawPayload::getCapacity() const
{
    return _capacity;
}

bool RawPayload::getOwned() const
{
    return _owned;
}
