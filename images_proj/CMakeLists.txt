cmake_minimum_required(VERSION 3.23)

project(ImageProject)

if (NOT CMAKE_BUILD_TYPE)           
    set(CMAKE_BUILD_TYPE Debug) 
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")   # for c++

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")                           # for c

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

# cmake -B build -DBUILD_TESTS=ON
option(BUILD_TESTS "Build tests" OFF) 

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(image_lib
    src/filters.cpp
    src/image.cpp
    src/pixel.cpp
)

target_include_directories(image_lib
    PUBLIC include      
)

add_executable(program 
    app/main.cpp)

target_link_libraries(program PRIVATE image_lib)  

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
    add_executable(tests 
        tests/compressor_tests.cpp
        tests/decompressor_tests.cpp
        tests/decrypt_chesar_tests.cpp
        tests/encrypt_chesar_tests.cpp
    )

    # connect out library and Catch2 to the tests program
    target_link_libraries(tests PRIVATE str_modes_lib Catch2::Catch2WithMain)

    # register and run tests executable with CTest
    add_test(NAME TestsStrModesFunction COMMAND $<TARGET_FILE:tests>) 
endif()
