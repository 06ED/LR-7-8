#include <gtest/gtest.h>

#include "../src/adapter/BookAdapter.h"


TEST(BookAdapterGroup, TestVectorBookAdapter) {
    BookAdapter<std::vector, std::string, int> books;
    ASSERT_EQ(books.getBooks().size(), 0);

    books.addBook({"title", "author", 2000, {2001, 2002}});
    ASSERT_EQ(books.getBooks().size(), 1);

    books.addBook({"title", "author", 2000, {2001, 2002, 2005}});
    ASSERT_EQ(books.getBooks().size(), 2);
    ASSERT_EQ(books.countUniqueReprints(), 3);
}

TEST(BookAdapterGroup, TestMultiSetSetBookAdapter) {
    BookAdapter<std::multiset, std::string, int> books;
    ASSERT_EQ(books.getBooks().size(), 0);

    books.addBook({"title1", "author1", 2000, {2001, 2002}});
    ASSERT_EQ(books.getBooks().size(), 1);

    books.addBook({"title2", "author2", 2001, {2003, 2004, 2005}});
    ASSERT_EQ(books.getBooks().size(), 2);
    ASSERT_EQ(books.countUniqueReprints(), 5);
}
