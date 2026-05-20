#pragma once

#include <string>

class Message {
public:
    Message() = default;

    virtual ~Message() = default; // virtual destructor

    Message(const Message&) = default;   // copy constructor
    Message& operator=(const Message&) = default; // copy assignment operator

    Message(Message&&) noexcept = default; // move constructor
    Message& operator=(Message&&) noexcept = default; // move assignment operator

    virtual std::string serialize() const = 0;
    virtual std::string type() const = 0;
};