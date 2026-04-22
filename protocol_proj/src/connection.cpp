#include "connection.hpp"
#include "protocol_handler.hpp"
#include <chrono>
#include <thread>
#include <random>

Connection::Connection(std::string_view endpoint)
    : _endpoint(endpoint), _connected(false)
{
}

void Connection::connect()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    _connected = true;
}

void Connection::disconnect()
{
    _connected = false;
}

std::string Connection::receive()
{
    if (!_connected)
        throw ConnectionTimeoutException("Connection error");

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist3(1,3);

    switch (dist3(rng)) {
        case 1:
            return "1.0|TEXT|Hello hse";
        case 2:
            return "1.0|BINARY|101010101011";
        case 3:
            return "1.0|TEXT|Some info";
    }

    return "1.0|TEXT|fallback";
}