#ifndef FICTION_BOOK_H
#define FICTION_BOOK_H

#include "Book.h"

#include <utility>

template<typename AuthorType, typename YearType>
class FictionBook : public Book<AuthorType, YearType> {
    std::string genre;
    bool bestseller{false};

public:
    FictionBook(
        std::string title,
        const AuthorType &author,
        const YearType &publicationYear,
        std::string genre,
        const bool bestseller,
        const std::vector<YearType> &reprints = {}
    ) : Book<AuthorType, YearType>(title, author, publicationYear, reprints),
        genre(std::move(genre)),
        bestseller(bestseller) {
    }

    FictionBook() = default;

    FictionBook(const FictionBook &other) = default;

    FictionBook(FictionBook &&other) noexcept = default;

    [[nodiscard]] std::string getGenre() const { return genre; }

    [[nodiscard]] bool isBestseller() const { return bestseller; }
};


#endif // FICTION_BOOK_H
