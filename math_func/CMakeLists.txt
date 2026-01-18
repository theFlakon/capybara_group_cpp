cmake_minimum_required(VERSION 3.23)

project(MathFunc)


if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Only for IK. If you use VScode just skip this

# If you wanna build the projects with the tests use the command below
# cmake -B build -DBUILD_TESTS=ON
option(BUILD_TESTS "Build tests" OFF)

add_library(pow_lib
    src/pow_func.cpp
)

target_include_directories(pow_lib
    PUBLIC include
)

add_executable(program app/main.cpp)
target_link_libraries(program PRIVATE pow_lib)

if (BUILD_TESTS)
    find_package(Catch2 3 REQUIRED)

    add_executable(tests tests/test.cpp)

    target_link_libraries(tests PRIVATE pow_lib Catch2::Catch2WithMain)
endif()
