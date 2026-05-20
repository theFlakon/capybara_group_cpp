#pragma once

#include "Message.hpp"

#include <vector>
#include <string>
#include <cstdint>

class BinaryMessage : public Message {
private:
    std::vector<uint8_t> _data;

public:
    explicit BinaryMessage(const std::vector<uint8_t>& data);

   
    ~BinaryMessage() override = default; // destructor

    
    BinaryMessage(const BinaryMessage& other) = default; // copy constructor

    
    BinaryMessage& operator=(const BinaryMessage& other) = default; // copy assignment operator

   
    BinaryMessage(BinaryMessage&& other) noexcept = default; // move constructor

  
    BinaryMessage& operator=(BinaryMessage&& other) noexcept = default; // move assignment operator

    const std::vector<uint8_t>& getData() const;
    void setData(const std::vector<uint8_t>& data);
    
    std::string serialize() const override;
    std::string type() const override;
};