#include "MessageBroker.hpp"

MessageBroker::MessageBroker(std::size_t cacheSize) : cache(cacheSize) {}

void MessageBroker::addMessage(const std::shared_ptr<Message>& message){
    if (!message)
    {
        throw std::invalid_argument("Message is empty");
    }

    queue.push_back(message);
}

size_t MessageBroker::size() const{
    return queue.size();
}

void MessageBroker::printSerialized() const{
    for (const auto& msg : queue)
    {
        std::cout << msg->serialize() << '\n';
    }
}

std::shared_ptr<Message> MessageBroker::front() const{
    if (queue.empty())
    {
        throw std::invalid_argument("Queue is empty");
    }

    return queue.front();
}