#pragma once

#include "message.hpp"
#include <condition_variable>
#include <mutex>
#include <queue>
#include <optional>

class MessageQueue
{
private:
    std::queue<Message> _queue;
    size_t _maxCapacity;

    std::mutex _mtx;                            // for that several threads do not climb in queue at the same time
    std::condition_variable _condVar;           // 

public:
    explicit MessageQueue(size_t maxCapacity);  // to create object explicitly (явно)
    ~MessageQueue();

    void push(const Message &msg);
    std::optional<Message> pop();               // or object exists or no (std::nullopt)

    bool empty() const;
    size_t size() const;
};
