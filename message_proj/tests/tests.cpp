#include <catch2/catch_test_macros.hpp>

#include "RawPayload.hpp"
#include "TextMessage.hpp"
#include "BinaryMessage.hpp"
#include "MessageBroker.hpp"

#include <memory>
#include <vector>
#include <cstdint>
#include <cstring>

TEST_CASE("RawPayload: construction", "[RawPayload]") {
    RawPayload p(128);
    CHECK(p.getCapacity() == 128);
    CHECK(p.getBuffer() != nullptr);
    CHECK(p.getOwned() == true);
}

TEST_CASE("RawPayload deep copy", "[RawPayload]") {
    RawPayload src(64);
    std::memset(src.getBuffer(), 0xAB, 64);

    RawPayload dst(src);

    REQUIRE(dst.getCapacity() == 64);
    REQUIRE(dst.getBuffer() != nullptr);
    CHECK(dst.getBuffer() != src.getBuffer());
    CHECK(dst.getOwned() == true);
    CHECK(std::memcmp(dst.getBuffer(), src.getBuffer(), 64) == 0);
}

TEST_CASE("RawPayload move constructor", "[RawPayload]") {
    RawPayload src(256);
    char* originalBuf = src.getBuffer();

    RawPayload dst(std::move(src));

    CHECK(dst.getBuffer() == originalBuf);
    CHECK(dst.getCapacity() == 256);
    CHECK(dst.getOwned() == true);

    CHECK(src.getBuffer() == nullptr);
    CHECK(src.getCapacity() == 0);
    CHECK(src.getOwned() == false);
}

TEST_CASE("type returns BINARY", "[BinaryMessage]") {
    BinaryMessage msg({0x01});
    CHECK(msg.type() == "BINARY");
}

TEST_CASE("getData returns original data", "[BinaryMessage]") {
    std::vector<uint8_t> data = {0xDE, 0xAD, 0xBE, 0xEF};
    BinaryMessage msg(data);
    CHECK(msg.getData() == data);
}

TEST_CASE("setData updates content", "[BinaryMessage]") {
    BinaryMessage msg({0x00});
    std::vector<uint8_t> newData = {0xFF, 0x01};
    msg.setData(newData);
    CHECK(msg.getData() == newData);
}

TEST_CASE("empty payload", "[BinaryMessage]") {
    BinaryMessage msg({});
    CHECK(msg.serialize() == "[]");
    CHECK(msg.getData().empty());
}

TEST_CASE("addMessage increases size", "[MessageBroker]") {
    MessageBroker broker(64);
    broker.addMessage(std::make_shared<TextMessage>("a"));
    broker.addMessage(std::make_shared<TextMessage>("b"));
    CHECK(broker.size() == 2);
}

TEST_CASE("MessageBroker front()", "[MessageBroker]") {
    MessageBroker broker(64);
    auto first = std::make_shared<TextMessage>("first");
    auto second = std::make_shared<TextMessage>("second");
    broker.addMessage(first);
    broker.addMessage(second);
    CHECK(broker.front()->serialize() == "first");
}
