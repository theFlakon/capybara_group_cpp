#include "message.hpp"
#include <condition_variable>
#include <mutex>
#include <queue>

class MessageQueue
{
private:
    std::queue<Message> _queue;
    size_t _maxVapacity;

    std::mutex _mtx;
    std::condition_variable _condVar;

public:
    explicit MessageQueue(size_t maxCapacity);

    void push(Message msg);
    std::optional<Message> pop();

    bool empty() const;
    size_t size() const;
};
