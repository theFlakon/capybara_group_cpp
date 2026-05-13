#include "BinaryMessage.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

BinaryMessage::BinaryMessage(const std::vector<uint8_t>& data) : _data(data) {
    std::cout << "[LOG] BinaryMessage created\n";
}

const std::vector<uint8_t>& BinaryMessage::getData() const {
    return _data;
}

void BinaryMessage::setData(const std::vector<uint8_t>& data) {
    _data = std::move(data);
}

std::string BinaryMessage::serialize() const {
    std::ostringstream oss;
    oss << "[";
    for (std::size_t i = 0; i < _data.size(); ++i) {
        if (i > 0) oss << " ";
        oss << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(_data[i]);
    }
    oss << "]";
    return oss.str();
}

std::string BinaryMessage::type() const {
    return "BINARY";
}