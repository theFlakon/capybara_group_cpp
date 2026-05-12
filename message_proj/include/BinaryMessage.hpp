#pragma once

#include "Message.hpp"

#include <vector>
#include <string>

class BinaryMessage : public Message {
private:
    std::vector<unsigned char> data;

public:
    explicit BinaryMessage(const std::vector<unsigned char>& data);

    std::string serialize() const override;
};