#pragma once

#include "message.hpp"
#include <expected>
#include <memory>
#include <stdexcept>
#include <string_view>
#include <variant>

class MalformedMessageException: public std::runtime_error
{
public:
    explicit MalformedMessageException(std::string_view what)
        : std::runtime_error(std::string(what)) {}
};
class ConnectionTimeoutException: public std::runtime_error
{
public:
    explicit ConnectionTimeoutException(std::string_view what)
        : std::runtime_error(std::string(what)) {}
};
class ProtocolVersionMismatchException: public std::runtime_error
{
public:
    explicit ProtocolVersionMismatchException(std::string_view what)
        : std::runtime_error(std::string(what)) {}
};

using ParseError = std::variant<MalformedMessageException, 
                                ConnectionTimeoutException,
                                ProtocolVersionMismatchException>;

class IProtocolParser
{
public:
    virtual ~IProtocolParser() = default;
    virtual std::expected<Message, ParseError> parse(std::string_view rawData) = 0;
};

class DefaultParser : public IProtocolParser {
public:
    std::expected<Message, ParseError> parse(std::string_view rawData) override;
};

class ProtocolHandler
{
public:
    explicit ProtocolHandler(std::string_view version, std::unique_ptr<IProtocolParser> parser = std::make_unique<DefaultParser>());
    std::expected<Message, ParseError> handle(std::string_view rawData);
private:
    std::string _version;
    std::unique_ptr<IProtocolParser> _parser;
    void validateVersion(const std::string& version) const;
};
