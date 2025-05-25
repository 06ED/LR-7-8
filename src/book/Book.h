#ifndef BOOK_H
#define BOOK_H

#include <algorithm>
#include <chrono>
#include <format>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template<typename AuthorType, typename YearType>
class Book {
    std::string title;
    AuthorType author;
    YearType publicationYear{2000};
    std::vector<YearType> reprints;

    void validateYear(YearType year) {
        if (year > now()) {
            throw std::logic_error("Publication year more than now");
        }

        if (!reprints.empty() && year > reprints.back()) {
            throw std::logic_error("Reprint year less than publication year");
        }
    }

    static int now() { return std::stoi(std::format("{:%Y}", std::chrono::system_clock::now())); }

public:
    Book(
        std::string title,
        const AuthorType &author,
        const YearType &publicationYear,
        const std::vector<YearType> &reprints = {}
    ) : title(std::move(title)) {
        validateYear(publicationYear);
        this->reprints = reprints;

        if (typeid(author) != typeid(std::string)) {
            throw std::invalid_argument("Invalid author");
        }
        this->author = author;
    }

    template<typename U, typename V>
    explicit Book(
        const Book<U, V> &other
    )
        : title(other.getTitle()),
          author(other.getAuthor()),
          publicationYear(other.getPublicationYear()),
          reprints(other.getReprints().begin(), other.getReprints().end()) {
    }

    Book(const Book &other) = default;

    Book(Book &&other)
        noexcept = default;

    Book() = default;

    void addReprint(const YearType &year) {
        if (year < publicationYear) {
            throw std::logic_error("Reprint year less than publication year");
        }

        reprints.push_back(year);
    }

    void printInfo() const {
        std::cout
                << "Book(title="
                << title
                << ", author="
                << author
                << ", publicationYear="
                << publicationYear
                << ", reprints=[";
        for (int i = 0; i < reprints.size(); i++) {
            if (i + 1 == reprints.size()) {
                std::cout << reprints[i];
                break;
            }

            std::cout << reprints[i] << ", ";
        }
        std::cout << "]" << std::endl;
    }

    [[nodiscard]] bool isReprinted() const { return !reprints.empty(); }

    YearType getLatestReprint() const { return *std::max_element(reprints.begin(), reprints.end()); }

    void updateAuthor(const AuthorType author) {
        if (author == "") {
            throw std::invalid_argument("Invalid author");
        }

        this->author = author;
    }

    Book operator+(const Book &other) const {
        Book result = *this;
        result.reprints.insert(result.reprints.end(), other.reprints.begin(), other.reprints.end());
        return result;
    }

    Book &operator+=(const YearType &year) {
        addReprint(year);
        return *this;
    }

    Book &operator++() {
        ++publicationYear;
        validateYear(publicationYear);
        return *this;
    }

    Book operator++(int) {
        Book temp = *this;
        ++*this;
        return temp;
    }

    Book &operator--() {
        --publicationYear;
        validateYear(publicationYear);
        return *this;
    }

    Book operator--(int) {
        Book temp = *this;
        --*this;
        return temp;
    }

    bool operator<(const Book &other) const { return publicationYear < other.publicationYear; }

    bool operator>(const Book &other) const { return publicationYear > other.publicationYear; }

    bool operator==(const Book &other) const { return publicationYear == other.publicationYear; }

    Book &operator=(const Book &other) = default;

    Book &operator=(Book &&other) noexcept = default;

    // Getters
    [[nodiscard]] std::string getTitle() const { return title; }

    AuthorType getAuthor() const { return author; }

    YearType getPublicationYear() const { return publicationYear; }

    const std::vector<YearType> &getReprints() const { return reprints; }
};

#endif // BOOK_H
