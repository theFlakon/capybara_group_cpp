#include "TextMessage.hpp"
#include <iostream>

TextMessage::TextMessage(const std::string& text) : _text(text) {
    std::cout << "[LOG] TextMessage created\n";
}

std::string TextMessage::serialize() const {
    return _text;
}

void TextMessage::setText(const std::string& text) {
    _text = text;
}

const std::string& TextMessage::getText() const {
    return _text;
}

std::string TextMessage::type() const {
    return "TEXT";
}
