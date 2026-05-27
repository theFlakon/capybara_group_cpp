# types_router

A C++ compile-time type dispatch system demonstrating template specialization, `if constexpr`, and compile-time type identification.

## Architecture

```
TypesRouter<T> (generic)
    TypeImplement<int> - multiplies by 10
    TypeImplement<double> - rounds to 1 decimal
    TypeImplement<std::string> - converts to uppercase
    TypeImplement<std::vector<T>> - computes element sum

type_id<T>() - constexpr type ID at compile time
route(value) - template function, deduces T from argument
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
