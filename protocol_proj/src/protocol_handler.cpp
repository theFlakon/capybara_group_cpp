#include "protocol_handler.hpp"


std::expected<Message, ParseError> DefaultParser::parse(std::string_view rawData) {
    std::vector<std::string_view> parts;
    std::string_view rest = rawData;
    while (true) {
        auto pos = rest.find('|');
        parts.push_back(rest.substr(0, pos));
        if (pos == std::string_view::npos) break;
        rest = rest.substr(pos + 1);
    }

    if (parts.size() != 3)
        return std::unexpected(ParseError{
            MalformedMessageException("Expected VERSION|TYPE|PAYLOAD")});

    std::string version(parts[0]);
    std::string type(parts[1]);
    std::string_view payloadSv = parts[2];

    if (type == "TEXT")
        return Message(std::move(version), std::move(type),
                    TextPayload{ std::string(payloadSv) });

    if (type == "BINARY") {
        for (char c : payloadSv) {
            if (c != '0' && c != '1') {
                return std::unexpected(ParseError{
                    MalformedMessageException("Non-binary char in payload")});
            }
        }
        BinaryPayload bp;
        for (char c : payloadSv)
            bp.data.push_back(static_cast<uint8_t>(c));
        return Message(std::move(version), std::move(type), std::move(bp));
    }

    return std::unexpected(ParseError{
        MalformedMessageException("Unknown type: " + std::string(type))});
}

ProtocolHandler::ProtocolHandler(std::string_view version, std::unique_ptr<IProtocolParser> parser)
    : _version(version), _parser(std::move(parser)) {}

void ProtocolHandler::validateVersion(const std::string& version) const {
    if (version != _version) {
        throw ProtocolVersionMismatchException("Expected " + _version + ", got " + version);
    }
}

std::expected<Message, ParseError> ProtocolHandler::handle(std::string_view rawData) {
    auto result = _parser->parse(rawData);
    if (!result) return result;

    validateVersion(result->getVersion());
    return result;
}
