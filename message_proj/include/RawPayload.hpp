#pragma once

#include <cstddef>

class RawPayload {
private:
    char* buffer;
    std::size_t capacity;
    bool owned;

public:
    explicit RawPayload(std::size_t capacity);

    ~RawPayload();

    // Rule of 5
    RawPayload(const RawPayload& other);
    RawPayload& operator=(const RawPayload& other);

    RawPayload(RawPayload&& other) noexcept;
    RawPayload& operator=(RawPayload&& other) noexcept;

    char* getBuffer() const;

    std::size_t getCapacity() const;
};