# message_proj

A C educational message broker demonstrating Rule of 5 resource management, smart pointers, and runtime polymorphism.

## Architecture

```
Message (abstract)
    TextMessage - string payload
    BinaryMessage - binary payload (vector<uint8_t>)

RawPayload - fixed-size buffer (char*), Rule of 5
MessageBroker - owns RawPayload cache + deque<shared_ptr<Message>>
```

## Build

```bash
cmake -B build
cmake --build build
./build/bin/program
```

## Tests

```bash
cmake -B build -DBUILD_TESTS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```
