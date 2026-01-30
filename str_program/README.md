````md
# str_program

**str_program** is an **educational console application written in C++**.  
The project demonstrates basic string processing algorithms, modular program structure,  
and multi-mode execution using **CMake**.

The application works in **interactive mode**:  
the operation mode is selected via a command-line flag, while input data is entered during program execution.

---

## Project Structure

```text
.
├── CMakeLists.txt
├── README.md
├── app
│   └── main.cpp
├── include
│   ├── compressor.h
│   ├── decompressor.h
│   ├── decrypt-chesar.h
│   └── encrypt-chesar.h
├── src
│   ├── compressor.cpp
│   ├── decompressor.cpp
│   ├── decrypt-chesar.cpp
│   └── encrypt-chesar.cpp
├── tests
│   ├── compressor_tests.cpp
│   ├── decompressor_tests.cpp
│   ├── decrypt_chesar_tests.cpp
│   └── encrypt_chesar_tests.cpp
└── build
    └── bin
        ├── program
        └── tests
````

---

## Build and Run

The project is built using **CMake**.

### Build

From the project root directory:

```bash
cmake -S . -B build
cmake --build build
```

### Run

After a successful build, the executable is located at:

```text
build/bin/program
```

Run the program with one of the available flags:

```bash
./build/bin/program <flag>
```

---

## Usage

### Help

```bash
./build/bin/program --help
```

Prints a list of available modes and flags.

---

### Available Modes

| Flag     | Mode           | Description                                                          |
| -------- | -------------- | -------------------------------------------------------------------- |
| `--help` | Help           | Prints help message with a list of available options                 |
| `-c`     | Compressor     | Compresses a string using a simple educational compression algorithm |
| `-d`     | Decompressor   | Restores a string compressed by the compressor mode                  |
| `-ec`    | Caesar Encrypt | Encrypts a string using the classical Caesar cipher                  |
| `-dc`    | Caesar Decrypt | Decrypts a string encrypted using the Caesar cipher                  |

---

## Examples

```bash
./build/bin/program -c
Enter your string: aaabbc
```

Output:

```text
3a2b1c
```

---

## Unit Tests

The project includes **unit tests for each module**, implemented using **Catch2**
and located in the `tests/` directory.

---

### Build with Unit Tests Enabled

To build the project **with unit tests**, configure CMake with the `BUILD_TESTS` option enabled:

```bash
cmake -S . -B build -DBUILD_TESTS=ON
cmake --build build
```

After a successful build, the following executables will be generated:

```text
build/bin/program   # main application
build/bin/tests     # unit tests executable
```

---

### Run Unit Tests

Unit tests can be run directly by executing the test binary:

```bash
./build/bin/tests
```

Example output:

```text
All tests passed (30 assertions in 4 test cases)
```

This confirms that all implemented modules work correctly.

