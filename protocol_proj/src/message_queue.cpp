#include "message_queue.hpp"

MessageQueue::MessageQueue(size_t maxCapacity) : 
    _maxCapacity(maxCapacity == 0 ? 1 : maxCapacity) {}

MessageQueue::~MessageQueue() = default;

bool MessageQueue::empty() const{
    std::unique_lock<std::mutex> lock(_mtx);
    return _queue.empty();
}

size_t MessageQueue::size() const{
    std::unique_lock<std::mutex> lock(_mtx);
    return _queue.size();
}

void MessageQueue::push(Message msg){
    // close other streams, we can change only queue
    std::unique_lock<std::mutex> lock(_mtx);

    // wait when there will be free place in queue
    _condVar.wait(lock, [this]()
    {
        return _queue.size() < _maxCapacity;
        // if false -> unlock mutex, sleep (wait other stream, notify), lock, check again
        // if true -> push :)
    });

    _queue.push(std::move(msg));    // don't copy
    _condVar.notify_one();            // if someone waits -> wake
}

Message MessageQueue::pop(){
    std::unique_lock<std::mutex> lock(_mtx);

    _condVar.wait(lock, [this]{
        return !_queue.empty();
        // if false -> unlock mutex, sleep (wait other stream, notify), lock, check again
        // if true -> continue
    });

    Message msg = std::move(_queue.front());
    _queue.pop();
    _condVar.notify_one();

    return msg;
}
