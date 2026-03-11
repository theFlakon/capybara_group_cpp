cmake_minimum_required(VERSION 3.23)
project(ImageProject)

if (NOT CMAKE_BUILD_TYPE)           
    set(CMAKE_BUILD_TYPE Debug) 
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

option(BUILD_TESTS "Build tests" OFF) 

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(OpenCV QUIET)

if(NOT OpenCV_FOUND)
    message(STATUS "OpenCV not found, download")
    include(FetchContent)
    
    FetchContent_Declare(
        opencv
        GIT_REPOSITORY https://github.com/opencv/opencv.git
        GIT_TAG 4.8.0
    )
    
    set(OPENCV_ENABLE_NONFREE OFF CACHE BOOL "" FORCE)
    set(BUILD_opencv_apps OFF CACHE BOOL "" FORCE)
    set(BUILD_opencv_java OFF CACHE BOOL "" FORCE)
    set(BUILD_opencv_python OFF CACHE BOOL "" FORCE)
    set(BUILD_opencv_js OFF CACHE BOOL "" FORCE)
    set(BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(BUILD_PERF_TESTS OFF CACHE BOOL "" FORCE)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    
    FetchContent_MakeAvailable(opencv)
endif()

add_library(image_lib
    src/file_parser.cpp
    src/pixel.cpp
    src/image.cpp
    src/history_manager.cpp
)

target_include_directories(image_lib
    PUBLIC include      
)

target_link_libraries(image_lib PRIVATE opencv_core opencv_imgcodecs)

add_executable(program 
    app/main.cpp
)

target_link_libraries(program PRIVATE image_lib)  

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

    target_link_libraries(tests PRIVATE image_lib Catch2::Catch2WithMain)
    add_test(NAME Tests COMMAND $<TARGET_FILE:tests>) 
endif()