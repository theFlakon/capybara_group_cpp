#pragma once

#include "Message.hpp"

#include <string>

class TextMessage : public Message {
private:
    std::string _text;

public:
    explicit TextMessage(const std::string& text);
  
    ~TextMessage() override = default; // destructor

    TextMessage(const TextMessage& other) = default; // copy constructor
  
    TextMessage& operator=(const TextMessage& other) = default; // copy assignment operator
   
    TextMessage(TextMessage&& other) noexcept = default; // move constructor
   
    TextMessage& operator=(TextMessage&& other) noexcept = default; // move assignment operator

    void setText(const std::string& text);
    const std::string& getText() const;

    std::string type() const override;
    std::string serialize() const override;

};