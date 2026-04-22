#include "message.hpp"

Message::Message(std::string version, std::string type,
                 std::variant<TextPayload, BinaryPayload> payload)
    : _version(std::move(version)), _type(std::move(type)),
      _payload(std::move(payload))
{
}

const std::string& Message::getVersion() const
{
    return _version;
}

const std::string& Message::getType() const
{
    return _type;
}

const std::variant<TextPayload, BinaryPayload>& Message::getPayload() const
{
    return _payload;
}

std::string Message::transformStrBin() const
{
    auto binPayload = std::get_if<BinaryPayload>(&_payload);
    std::string resultStr{};

    if(!binPayload)
    {
        auto textPayload = std::get_if<TextPayload>(&_payload);
        return textPayload->text;
    }

    for(size_t idx = 0; idx < binPayload->data.size(); ++idx)
        resultStr += static_cast<char>(binPayload->data[idx]);

    return resultStr;
}
