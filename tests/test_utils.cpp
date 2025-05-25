#include <gtest/gtest.h>

#include "../src/utils.h"
#include "../src/book/Book.h"


TEST(BookAdapterGroup, TestSortByReprints) {
    const std::vector<Book<std::string, int> > books{
        {"title", "author", 2000, {2001, 2002}},
        {"title", "author", 2000, {2001, 2002, 2010, 2020}},
        {"title", "author", 2000, {2001, 2002, 2004}},
    };
    const auto sortedBooks = sortByReprints(books);

    ASSERT_EQ(sortedBooks.front().getReprints().size(), 2);
    ASSERT_EQ(sortedBooks.back().getReprints().size(), 4);
}

TEST(BookAdapterGroup, TestFindByAuthor) {
    const std::vector<Book<std::string, int> > books{
        {"title", "author", 2000, {2001, 2002}},
        {"title", "author", 2000, {2001, 2002, 2010, 2020}},
        {"title", "author22", 2000, {2001, 2002, 2004}},
    };
    const auto sortedBooks = findByAuthor(books, std::string{"author"});

    ASSERT_EQ(sortedBooks.size(), 2);
}
