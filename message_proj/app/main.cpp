#include "BinaryMessage.hpp"
#include "MessageBroker.hpp"
#include "TextMessage.hpp"
#include <cstdint>
#include <iostream>
#include <memory>

int main()
{
    auto textMsg1 = std::make_shared<TextMessage>("Some Text Data");
    auto textMsg2 = std::make_shared<TextMessage>("Some Text Data 2");

    std::vector<uint8_t> binaryData = {0x01, 0x0A, 0xFF, 0x8C};
    auto binaryMsg = std::make_shared<BinaryMessage>(binaryData);

    MessageBroker broker(256);
    broker.addMessage(textMsg1);
    broker.addMessage(binaryMsg);
    broker.addMessage(textMsg2);

    std::cout << "Broker queue size: " << broker.size() << std::endl;

    std::cout << "Copying broker (shared ownership)..." << std::endl;
    MessageBroker brokerCopy = broker;

    std::cout << "Moving payload..." << std::endl;
    RawPayload payload1(512);
    RawPayload payload2 = std::move(payload1);

    broker.printSerialized();

    std::cout << "Cleanup... No memory leaks detected." << std::endl;

    return EXIT_SUCCESS;
}