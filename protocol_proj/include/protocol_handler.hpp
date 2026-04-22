#pragma once

#include "message.hpp"
#include <expected>
#include <stdexcept>
#include <string_view>
#include <variant>

class MalformedMessageException: public std::runtime_error
{
};
class ConnectionTimeoutException: public std::runtime_error
{
};
class ProtocolVersionMismatchException: public std::runtime_error
{
};

using ParseError =
    std::variant<MalformedMessageException, ConnectionTimeoutException,
                 ProtocolVersionMismatchException>;

class IProtocolParser
{
public:
    virtual ~IProtocolParser() = default;

    virtual std::expected<Message, ParseError>
    parse(std::string_view rawData) = 0;
};

class ProtocolHandler: public IProtocolParser
{
private:
    std::string _version;

public:
    explicit ProtocolHandler(std::string_view version);

    std::expected<Message, ParseError> parse(std::string_view rawData) override;

private:
    void validateVersion(const std::string& version) const;
};
