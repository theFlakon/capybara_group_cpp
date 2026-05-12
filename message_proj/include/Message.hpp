#pragma once

#include <string>

class Message {
public:
    virtual ~Message() = default;

    virtual std::string serialize() const = 0;
    virtual std::string type() const = 0;
};