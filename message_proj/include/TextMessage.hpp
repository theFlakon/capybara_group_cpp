#pragma once

#include "Message.hpp"

#include <string>

class TextMessage : public Message {
private:
    std::string _text;

public:
    explicit TextMessage(const std::string& text);
  
    ~TextMessage() override = default; // Destructor

    TextMessage(const TextMessage& other) = default; // Copy constructor
  
    TextMessage& operator=(const TextMessage& other) = default; // Copy assignment operator
   
    TextMessage(TextMessage&& other) noexcept = default; // Move constructor
   
    TextMessage& operator=(TextMessage&& other) noexcept = default; // Move assignment operator

    void setText(const std::string& text);
    const std::string& getText() const;

    std::string type() const override;
    std::string serialize() const override;

};