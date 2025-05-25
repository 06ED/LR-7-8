cmake_minimum_required(VERSION 3.31)

project(sources)

add_executable(app
        main.cpp
        utils.h
        book/Book.h
        book/FictionBook.h
        book/ScienceBook.h
        adapter/BookAdapter.h
)

target_link_libraries(app PRIVATE sources)
