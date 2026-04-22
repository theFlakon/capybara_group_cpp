#include <catch2/catch_test_macros.hpp>
#include "message.hpp"
#include "message_queue.hpp"

TEST_CASE("binary message") {
    BinaryPayload bin{{72, 101, 108, 108, 111}};

    Message msg("1", "BINARY", bin);

    REQUIRE(msg.getVersion() == "1");
    REQUIRE(msg.getType() == "BINARY");
    REQUIRE(msg.transformStrBin() == "Hello");
}

TEST_CASE("MessageQueue is empty after construction") {
    MessageQueue queue(3);

    REQUIRE(queue.empty());
    REQUIRE(queue.size() == 0);
}

TEST_CASE("push adds message to queue") {
    MessageQueue queue(3);
    Message msg("1", "TEXT", TextPayload{"Hello"});

    queue.push(std::move(msg));

    REQUIRE_FALSE(queue.empty());
    REQUIRE(queue.size() == 1);
}

TEST_CASE("pop returns pushed message") {
    MessageQueue queue(3);
    Message msg("1", "TEXT", TextPayload{"Hello"});

    queue.push(Message("1", "TEXT", TextPayload{"Hello"}));
    Message result = queue.pop();

    REQUIRE(result.getVersion() == "1");
    REQUIRE(result.getType() == "TEXT");
    REQUIRE(result.transformStrBin() == "Hello");

    REQUIRE(queue.empty());
    REQUIRE(queue.size() == 0);
}