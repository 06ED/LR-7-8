#include <gtest/gtest.h>

#include "../src/book/FictionBook.h"


TEST(FictionBookGroup, TestConstructor) {
    const FictionBook<std::string, int> book{
        "title",
        "author",
        2000,
        "year",
        true,
        {2020, 2035}
    };

    ASSERT_EQ(book.getTitle(), "title");
    ASSERT_EQ(book.isBestseller(), true);
}


TEST(FictionBookGroup, TestMethods) {
    const FictionBook<std::string, int> book;

    ASSERT_EQ(book.isBestseller(), false);
    ASSERT_EQ(book.getGenre(), "");
}
