#ifndef BOOK_ADAPTER_H
#define BOOK_ADAPTER_H

#include <set>
#include <map>

#include "../book/Book.h"

template<template <typename...> class Container, typename AuthorType, typename YearType>
class BookAdapter {
    Container<Book<AuthorType, YearType> > books;

public:
    void addBook(Book<AuthorType, YearType> book) {
        if constexpr (std::is_same_v<Container<Book<AuthorType, YearType> >, std::map<Book<AuthorType, YearType>,
            int> >) {
            throw std::invalid_argument("Map container not supported for books");
        }

        books.insert(books.end(), book);
    }

    [[nodiscard]] size_t countUniqueReprints() const {
        std::set<YearType> uniqueYears;

        for (const auto &book: books) {
            if (book.getAuthor() == "") {
                throw std::invalid_argument("Book doesn't have any author");
            }

            for (const auto &year: book.getReprints()) {
                uniqueYears.insert(year);
            }
        }

        return uniqueYears.size();
    }

    const Container<Book<AuthorType, YearType> > &getBooks() const { return books; }
};


#endif // BOOK_ADAPTER_H
