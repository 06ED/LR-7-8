cmake_minimum_required(VERSION 3.31)
project(LR_7)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 20)
enable_testing()

option(BUILD_TESTS "Build tests" ON)

add_subdirectory(src)
link_directories(src)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif ()
