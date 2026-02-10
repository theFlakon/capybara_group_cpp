cmake_minimum_required(VERSION 3.23)

project(MatrixTask)

if (NOT CMAKE_BUILD_TYPE)           
    set(CMAKE_BUILD_TYPE Debug) 
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")   

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")                           

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

# If you wanna build the projects with the tests use the command below
# cmake -B build -DBUILD_TESTS=ON
option(BUILD_TESTS "Build tests" OFF) 

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(matrix_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compressor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/decompressor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/get_element.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/add_sparse.cpp
)

target_include_directories(matrix_lib
    PUBLIC include      
)

add_executable(program 
    app/main.cpp
    app/local/io_funcs.cpp)

target_include_directories(program PRIVATE app/local/)
target_link_libraries(program matrix_lib)

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
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/compressor_tests.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/decompressor_tests.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/get_element_tests.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/add_sparse_tests.cpp
    )

    target_link_libraries(tests PRIVATE matrix_lib Catch2::Catch2WithMain)

    add_test(NAME TestsMatrixLibFunction COMMAND $<TARGET_FILE:tests>) 
endif()
