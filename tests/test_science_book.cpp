#include <gtest/gtest.h>

#include "../src/book/ScienceBook.h"

TEST(ScienceBookGroup, TestConstructors) {
    const ScienceBook<std::string, int> book{
        "title",
        "author",
        2000,
        true,
        {2010, 2020},
        {"first", "second"}
    };

    ASSERT_EQ(book.getTitle(), "title");
    ASSERT_EQ(book.getReferences().size(), 2);
}

TEST(ScienceBookGroup, TestMethods) {
    const ScienceBook<std::string, int> book;

    ASSERT_EQ(book.getTitle(), "");
    ASSERT_EQ(book.getReferences().empty(), true);
    ASSERT_EQ(book.isPeerReviewed(), false);
}
