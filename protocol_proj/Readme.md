# Educational Network Protocol Simulator

This project simulates a simple network protocol pipeline: receiving, parsing, and storing messages.

## Architecture

The system is built using four core components:

* **Connection**
  Simulates a network source and provides raw byte data.

* **ProtocolHandler**
  Responsible for parsing raw data and validating message format and protocol version.

* **Message**
  A structured representation of parsed data (header + payload).

* **MessageQueue**
  A thread-safe queue used to store valid messages for further processing.

## Data Flow

```
Connection → ProtocolHandler → Message → MessageQueue
```

## Error Handling

The system handles different types of errors:

* Malformed messages (invalid format)
* Connection timeouts
* Protocol version mismatch

## Goal

The goal of this project is to practice:

* Object-Oriented Programming (OOP)
* Separation of responsibilities
* Modern C++ features
* Basic network architecture concepts
  