#pragma once

#include "Message.hpp"

#include <string>

class TextMessage : public Message {
private:
    std::string _text;

public:
    explicit TextMessage(const std::string& text);
    void setText(const std::string& text);
    const std::string& getText() const;

    std::string type() const override;
    std::string serialize() const override;

};