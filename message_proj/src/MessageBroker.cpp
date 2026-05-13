#include "MessageBroker.hpp"
#include <iostream>

MessageBroker::MessageBroker(std::size_t cacheSize) : _cache(cacheSize) {}

void MessageBroker::addMessage(const std::shared_ptr<Message>& message){
    if (!message)
    {
        throw std::invalid_argument("Message is empty");
    }

    _queue.push_back(message);
}

size_t MessageBroker::size() const{
    return _queue.size();
}

void MessageBroker::printSerialized() const{
    for (const auto& msg : _queue) {
        if (msg->type() == "TEXT") {
            std::cout << "Serialized TextMessage: \"" << msg->serialize() << "\"\n";
        } else {
            std::cout << "Serialized BinaryMessage: " << msg->serialize() << "\n";
        }
    }
}

long MessageBroker::frontRefCount() const {
    if (_queue.empty())
        throw std::invalid_argument("Queue is empty");
        
    return _queue.front().use_count();
}

std::shared_ptr<Message> MessageBroker::front() const{
    if (_queue.empty())
    {
        throw std::invalid_argument("Queue is empty");
    }

    return _queue.front();
}