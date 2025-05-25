#ifndef UTILS_H
#define UTILS_H

#include <vector>

#include "book/Book.h"

template<typename AuthorType, typename YearType>
std::vector<Book<AuthorType, YearType> > sortByReprints(const std::vector<Book<AuthorType, YearType> > &books) {
    if (books.empty()) {
        throw std::invalid_argument("Cannot sort empty book list");
    }

    std::vector<Book<AuthorType, YearType> > sorted = books;
    std::sort(sorted.begin(), sorted.end(),
              [](const auto &a, const auto &b) {
                  return a.getReprints().size() < b.getReprints().size();
              });

    return sorted;
}

template<typename AuthorType, typename YearType>
std::vector<Book<AuthorType, YearType> > findByAuthor(
    const std::vector<Book<AuthorType, YearType> > &books,
    const AuthorType &author
) {
    if constexpr (std::is_same_v<AuthorType, std::string>) {
        if (author.empty()) {
            throw std::invalid_argument("Author cannot be empty");
        }
    }

    std::vector<Book<AuthorType, YearType> > result;
    for (const auto &book: books) {
        if (book.getAuthor() == author) {
            result.push_back(book);
        }
    }

    return result;
}

#endif // UTILS_H
