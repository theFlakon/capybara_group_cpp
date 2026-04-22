#include <cstdint>
#include <string>
#include <variant>
#include <vector>

struct TextPayload
{
    std::string text;
};

struct BinaryPayload
{
    std::vector<uint8_t> data;
};

class Message
{
private:
    std::string _version;
    std::string _type;  // E.g.: text, binary
    std::variant<TextPayload, BinaryPayload> _payload;

public:
    Message(std::string version, std::string type,
            std::variant<TextPayload, BinaryPayload> payload);

    const std::string& getVersion() const;
    const std::string& getType() const;
    const std::variant<TextPayload, BinaryPayload>& getPayload() const;

    std::string transformStrBin() const;
};
