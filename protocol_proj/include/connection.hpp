#pragma once

#include <string>
#include <string_view>

class Connection
{
private:
    std::string _endpoint;
    bool _connected = false;

public:
    explicit Connection(std::string_view endpoint);

    void connect();
    void disconnect();

    std::string receive();
};
