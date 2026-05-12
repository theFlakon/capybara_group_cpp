#pragma once

#include "RawPayload.hpp"
#include "Message.hpp"

#include <deque>
#include <memory>
#include <cstddef>
#include <iostream>

class MessageBroker {
private:
    RawPayload cache;
    std::deque<std::shared_ptr<Message>> queue;

public:
    explicit MessageBroker(std::size_t cacheSize);

    void addMessage(const std::shared_ptr<Message>& message);

    size_t size() const;

    void printSerialized() const;

    std::shared_ptr<Message> front() const;
};