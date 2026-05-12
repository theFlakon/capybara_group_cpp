#include "BinaryMessage.hpp"

BinaryMessage::BinaryMessage(const std::vector<uint8_t>& data) : _data(data) {}

const std::vector<uint8_t>& BinaryMessage::getData() const {
    return _data;
}

void BinaryMessage::setData(const std::vector<uint8_t>& data) {
    _data = std::move(data);
}

std::string BinaryMessage::serialize() const {
    std::string result{};
    for (const auto& byte : _data) {
        result += std::to_string(byte) + " ";
    }
    return result;
}

std::string BinaryMessage::type() const {
    return "BINARY";
}