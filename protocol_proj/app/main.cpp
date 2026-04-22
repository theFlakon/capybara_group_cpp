#include "connection.hpp"
#include "message_queue.hpp"
#include "protocol_handler.hpp"
// мб работает мб нет без parse не скажешь
#include <iostream>
#include <variant>

int main()
{
    Connection conn("127.0.0.1:8080");
    ProtocolHandler parser("1.0");
    MessageQueue queue(10);

    try {
        conn.connect();
        std::cout << "Connected successfully\n";

        for (int idx = 0; idx < 5; idx++) {
            try {
                std::string rawData = conn.receive();
                std::cout << "Raw data: " << rawData << '\n';

                auto result = parser.parse(rawData);

                if (result) {
                    Message msg = *result;
                    queue.push(std::move(msg));
                    std::cout << "Message added to queue\n";
                } else {
                    std::cout << "Parsing failed\n";
                }

            } catch (const MalformedMessageException& e) {
                std::cout << "Malformed message: " << e.what() << '\n';
            } catch (const ProtocolVersionMismatchException& e) {
                std::cout << "Version mismatch: " << e.what() << '\n';
            } catch (const ConnectionTimeoutException& e) {
                std::cout << "Timeout: " << e.what() << '\n';
            }
        }

        conn.disconnect();
        std::cout << "\nDisconnected\n";

        std::cout << "\nProcessing queue:\n";

        while (!queue.empty()) {
            Message msg = queue.pop();

            std::cout << "Version: " << msg.getVersion() << '\n';
            std::cout << "Type: " << msg.getType() << '\n';

            std::visit([](const auto& payload) {
                using T = std::decay_t<decltype(payload)>;

                if constexpr (std::is_same_v<T, TextPayload>) {
                    std::cout << "Text payload: " << payload.text << '\n';
                } else if constexpr (std::is_same_v<T, BinaryPayload>) {
                    std::cout << "Binary payload: ";
                    for (auto byte : payload.data) {
                        std::cout << static_cast<int>(byte) << ' ';
                    }
                    std::cout << '\n';
                }
            }, msg.getPayload());

            std::cout << "----\n";
        }

    } catch (const std::exception& e) {
        std::cout << "Fatal error: " << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}