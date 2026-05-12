#pragma once

#include "Message.hpp"

#include <string>

class TextMessage : public Message {
private:
    std::string text;

public:
    explicit TextMessage(const std::string& text);

    std::string serialize() const override;
};