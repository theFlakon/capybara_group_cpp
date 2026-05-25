cmake_minimum_required(VERSION 3.22)
project(vars_router)

if (NOT CMAKE_BUILD_TYPE)           
    set(CMAKE_BUILD_TYPE Debug) 
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

option(BUILD_TESTS "Build tests" OFF) 

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(message_lib
)

target_include_directories(message_lib
    PUBLIC include
)

add_executable(program 
    app/main.cpp
)

target_link_libraries(program PRIVATE message_lib)

if (BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(   
        Catch2                                                
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0                                        
    )
    FetchContent_MakeAvailable(Catch2)                        

    enable_testing()                                          

    add_executable(tests 
        tests/tests.cpp
    )

    target_include_directories(tests PRIVATE include)

    target_link_libraries(tests 
        PRIVATE 
        Catch2::Catch2WithMain 
        message_lib
    )

    add_test(NAME Tests COMMAND $<TARGET_FILE:tests>) 
endif()
