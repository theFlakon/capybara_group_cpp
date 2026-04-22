#include "message_queue.hpp"
#include "message.hpp"
#include <mutex>

MessageQueue::MessageQueue(size_t maxCapacity) : 
    _maxCapacity(maxCapacity == 0 ? 1 : maxCapacity) {}

MessageQueue::~MessageQueue(){
    while (!empty()) {
        pop();
    }
}

bool MessageQueue::empty() const {
    if (size() == 0) return true;
    return false;
}

size_t MessageQueue::size() const {
    return _queue.size();
}

void MessageQueue::push(const Message &msg) {
    // close access
    std::lock_guard<std::mutex> lock(_mtx);

    // wait when there will be free place in queue
    _condVar.wait(lock, [this]()
    {
        return _queue.size() < _maxCapacity;
    });

    _queue.push(msg);
    lock.unlock();
}