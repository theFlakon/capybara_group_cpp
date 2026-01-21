This is a educational program for HSE C++ seminars. This program creates pow function(for positive and non-zero exp only) and tests module for it

For building with tests use:
cmake -B build -DBUILD_TESTS=ON

For building without tests use(tests module is disabled by default)
cmake -B build

Program usage:
./build/program <base> <exp>
Example:
./build/program 2 10

Tests module usage:
./build/tests
