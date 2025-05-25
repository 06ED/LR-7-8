#ifndef SCIENCE_BOOK_H
#define SCIENCE_BOOK_H

#include "Book.h"

template<typename AuthorType, typename YearType>
class ScienceBook : public Book<AuthorType, YearType> {
    std::vector<std::string> references;
    bool reviewed{false};

public:
    ScienceBook(std::string title,
                const AuthorType &author,
                const YearType &publicationYear,
                const bool reviewed,
                const std::vector<YearType> &reprints = {},
                const std::vector<std::string> &references = {}
    ) : Book<AuthorType, YearType>(title, author, publicationYear, reprints),
        references(references),
        reviewed(reviewed) {
    }

    ScienceBook(const ScienceBook &other) = default;

    ScienceBook(ScienceBook &&other) noexcept = default;

    ScienceBook() = default;

    [[nodiscard]] const std::vector<std::string> &getReferences() const { return references; }

    [[nodiscard]] bool isPeerReviewed() const { return reviewed; }
};

#endif // SCIENCE_BOOK_H
