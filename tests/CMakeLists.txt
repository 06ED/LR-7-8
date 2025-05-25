cmake_minimum_required(VERSION 3.31)

include(GoogleTest)

add_executable(tests
        test_book.cpp
        test_fiction_book.cpp
        test_science_book.cpp
        test_utils.cpp
        test_book_adapter.cpp
)

target_link_libraries(tests
        PRIVATE
        GTest::gtest_main
)

gtest_discover_tests(tests)