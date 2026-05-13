#pragma once

#include "RawPayload.hpp"
#include "Message.hpp"

#include <deque>
#include <memory>
#include <cstddef>

class MessageBroker {
private:
    RawPayload _cache;
    std::deque<std::shared_ptr<Message>> _queue;

public:
    explicit MessageBroker(std::size_t cacheSize);

    void addMessage(const std::shared_ptr<Message>& message);

    size_t size() const;

    void printSerialized() const;

    long frontRefCount() const;

    std::shared_ptr<Message> front() const;
};