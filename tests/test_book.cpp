#include <gtest/gtest.h>

#include "../src/book/Book.h"

TEST(BookGroup, TestDefaultConstructor) {
    const Book<std::string, int> book;

    ASSERT_EQ(book.getTitle(), "");
    ASSERT_EQ(book.getAuthor(), "");
    ASSERT_EQ(book.getPublicationYear(), 2000);
    ASSERT_EQ(book.getReprints().empty(), true);
}

TEST(BookGroup, TestOtherConstructors) {
    const Book<std::string, int> book{"title", "author", 2000, {2001, 2002}};
    const Book copyBook{book}; // NOLINT(*-unnecessary-copy-initialization)

    ASSERT_EQ(book.getTitle(), "title");
    ASSERT_EQ(book.getTitle(), copyBook.getTitle());
    ASSERT_EQ(book, copyBook);
}

TEST(BookGroup, TestOverridedOperators) {
    Book<std::string, int> book{"title", "author", 2000, {2005, 2010}};
    const Book copyBook{book};
    Book newBook = book + copyBook;

    ASSERT_EQ(book++.getPublicationYear(), 2000);
    ASSERT_EQ(book.getPublicationYear(), 2001);

    ASSERT_EQ((++book).getPublicationYear(), 2002);
    ASSERT_EQ(book.getPublicationYear(), 2002);

    ASSERT_EQ((--book).getPublicationYear(), 2001);
    ASSERT_EQ(book.getPublicationYear(), 2001);

    ASSERT_EQ(book--.getPublicationYear(), 2001);
    ASSERT_EQ(book.getPublicationYear(), 2000);

    ASSERT_EQ(newBook.getReprints().size(), book.getReprints().size() + copyBook.getReprints().size());

    newBook += 2020;
    ASSERT_EQ(newBook.getLatestReprint(), 2020);
}


TEST(BookGroup, TestMethods) {
    Book<std::string, int> book{"title", "author", 2000, {2001, 2002}};

    ASSERT_EQ(book.isReprinted(), true);

    book.updateAuthor("new");
    ASSERT_EQ(book.getAuthor(), "new");

    ASSERT_EQ(book.getLatestReprint(), 2002);
}
