#ifndef RAWPAYLOAD_HPP
#define RAWPAYLOAD_HPP

#include <cstring>

class RawPayload
{
private:
    char* _buffer;
    size_t _capacity;
    bool _owned;

public:
    explicit RawPayload(size_t cap);

    ~RawPayload();

    RawPayload(const RawPayload& other);

    RawPayload& operator=(const RawPayload& other);

    RawPayload(RawPayload&& other) noexcept;

    RawPayload& operator=(RawPayload&& other) noexcept;

    void setBuffer(char* buffer);

    void setCapacity(size_t capacity);

    void setOwned(bool owned);

    char* getBuffer();

    const char* getBuffer() const;

    size_t getCapacity() const;

    bool getOwned() const;
};

#endif
