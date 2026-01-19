cmake_minimum_required(VERSION 3.23)

project(MathFunc)

# CMAKE_BUILD_TYPE - variable, decribing assembley mode (rejim sborki); can be Debug (for education and debugging) or Release (fast version) in console
if (NOT CMAKE_BUILD_TYPE)           
    set(CMAKE_BUILD_TYPE Debug) # if isn`t there - set Debug
endif(NOT CMAKE_BUILD_TYPE)

# CMAKE_CXX_STANDARD - variable, describing c-standart (ex: 11, 17, 20)
set(CMAKE_CXX_STANDARD 17)

# the following options prevent compiler-optimization issues that are unwanted in an edu process, we are disabling it
# CMAKE_C_FLAGS_DEBUG - variable, describing compiler`s flags for Debug (ex: -g -O0 - Wall)
# we choose -O0 (off compiler`s options) and -Werror=return-type (if there`s NO "return" in func - ERROR ha-ha-ha)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")

# CMAKE_CXX_FLAGS_DEBUG - variable; we add -O0 
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

# CMAKE_EXPORT_COMPILE_COMMANDS - variable; is responsible only for 1 thing - create or not create file compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Only for IK. If you use VScode just skip this

# If you wanna build the projects with the tests use the command below
# cmake -B build -DBUILD_TESTS=ON
option(BUILD_TESTS "Build tests" OFF)

# just creating library
add_library(pow_lib
    src/pow_func.cpp
)

# we tell compiler "headlines lay in folder include"
target_include_directories(pow_lib
    PUBLIC include
)

# сompile the program named "program" from the file app/main.cpp
add_executable(program app/main.cpp)

# connect the pow_lib library to the program, linkovka
target_link_libraries(program PRIVATE pow_lib)

if (BUILD_TESTS)
    find_package(Catch2 3 REQUIRED)      # without Catch2 this include file will not be found, the test won`t compile

    add_executable(tests tests/test.cpp) # compile the "tests" program from the file tests/test.cpp
    
    # connect the pow_lib library and Catch2 to the tests program
    target_link_libraries(tests PRIVATE pow_lib Catch2::Catch2WithMain)
endif()