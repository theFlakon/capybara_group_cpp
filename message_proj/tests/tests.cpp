#include <catch2/catch_test_macros.hpp>

#include <cstdint>
#include "RawPayload.hpp"
#include <vector>
#include <memory>
#include "TextMessage.hpp"
#include "BinaryMessage.hpp"
#include "MessageBroker.hpp"
#include <cstring>

TEST_CASE("RawPayload copy constructor makes deep copy", "[RawPayload]") {
    RawPayload src(64);
    std::memset(src.getBuffer(), 0xAB, 64);

    RawPayload dst(src);

    REQUIRE(dst.getBuffer() != nullptr);
    CHECK(dst.getBuffer() != src.getBuffer());
    CHECK(dst.getCapacity() == 64);
    CHECK(dst.getOwned() == true);
    CHECK(std::memcmp(dst.getBuffer(), src.getBuffer(), 64) == 0);
}

TEST_CASE("RawPayload copy assignment makes deep copy", "[RawPayload]") {
    RawPayload src(64);
    std::memset(src.getBuffer(), 0xCD, 64);

    RawPayload dst(32);
    dst = src;

    CHECK(dst.getBuffer() != src.getBuffer());
    CHECK(dst.getCapacity() == 64);
    CHECK(std::memcmp(dst.getBuffer(), src.getBuffer(), 64) == 0);
}

TEST_CASE("RawPayload move constructor transfers ownership", "[RawPayload]") {
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

TEST_CASE("RawPayload move assignment transfers ownership", "[RawPayload]") {
    RawPayload src(128);
    char* originalBuf = src.getBuffer();

    RawPayload dst(32);
    dst = std::move(src);

    CHECK(dst.getBuffer() == originalBuf);
    CHECK(dst.getCapacity() == 128);
    CHECK(src.getBuffer() == nullptr);
    CHECK(src.getCapacity() == 0);
}

TEST_CASE("TextMessage serialize returns text", "[TextMessage]") {
    TextMessage msg("Hello, C++ Seminar!");
    CHECK(msg.serialize() == "Hello, C++ Seminar!");
}

TEST_CASE("TextMessage copy works", "[TextMessage]") {
    TextMessage a("original");
    TextMessage b = a;
    b.setText("changed");
    CHECK(a.getText() == "original");
    CHECK(b.getText() == "changed");
}

TEST_CASE("BinaryMessage copy works", "[BinaryMessage]") {
    std::vector<uint8_t> data = {0xDE, 0xAD};
    BinaryMessage a(data);
    BinaryMessage b = a;
    b.setData({0x00});
    CHECK(a.getData() == data);
}

TEST_CASE("MessageBroker addMessage and size", "[MessageBroker]") {
    MessageBroker broker(64);
    broker.addMessage(std::make_shared<TextMessage>("a"));
    broker.addMessage(std::make_shared<BinaryMessage>(std::vector<uint8_t>{0x01}));
    CHECK(broker.size() == 2);
}