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
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")   # for c++

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")                           # for c

# CMAKE_EXPORT_COMPILE_COMMANDS - variable; it is responsible only for 1 thing - create or not create file compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Only for JetBrains. If you use VScode just skip this

# If you wanna build the projects with the tests use the command below
# cmake -B build -DBUILD_TESTS=ON
option(BUILD_TESTS "Build tests" OFF) 

# where to put bin files (build/bin/program)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# where to put static libraries (build/lib/libpow_lib.a)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# where to put dynamic libraries (build/lib/libpow_lib.so) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# just creating library
add_library(pow_lib
    src/pow_func.cpp
)

# we tell compiler "headlines lie in folder include"
target_include_directories(pow_lib
    PUBLIC include      # link lib and headline, PUBLIC because we will need this header later (48 line)
)

# сompile the program named "program" from the file app/main.cpp
add_executable(program app/main.cpp)

# connect the pow_lib library to the program, linkovka
target_link_libraries(program PRIVATE pow_lib)  # PRIVATE because we don`t want access to pow_lib from program

if (BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(   
        Catch2                                                # declare dependency catch2 from        
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git # where to download
        GIT_TAG v3.4.0                                        # version
    )
    FetchContent_MakeAvailable(Catch2)                        # download catch2 into build, add as a part of assembley, create targets type Catch2::Catch2WithMain

    enable_testing()                                          # enables support for tests in CMake/CTest for add_test (67) could work
    
    # сompile the program named "tests" from the file tests/test.cpp
    add_executable(tests tests/test.cpp)

    # connect the pow_lib library and Catch2 to the tests program
    target_link_libraries(tests PRIVATE pow_lib Catch2::Catch2WithMain)

    # register and run tests executable with CTest
    add_test(NAME TestsPowFunction COMMAND $<TARGET_FILE:tests>) 
endif()
