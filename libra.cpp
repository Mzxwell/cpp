//
// Created by Jinx on 24-11-23.
//
#include <iostream>
#include <memory>
#include <string>
#include <cassert>
#include <unordered_map>
#include <functional>

class BorrowStrategy {
public:
    virtual ~BorrowStrategy() = default;

    virtual double calculate(int days) const = 0;
};

class DailyBorrowStrategy : public BorrowStrategy {
public:
    DailyBorrowStrategy() {}

    double calculate(int days) const override { return days * 1.0; }
};

class MemberBorrowStrategy : public BorrowStrategy {
public:
    MemberBorrowStrategy(std::string level) : memberLevel(level) {}

    double calculate(int days) const override {
        int weeks = (days + 6) / 7;
        double discount = 1.0;
        if (memberLevel == "REGULAR") discount = 0.95;
        else if (memberLevel == "GOLD") discount = 0.85;
        else if (memberLevel == "PLATINUM")discount = 0.75;
        return weeks * 5 * discount;
    }

private:
    std::string memberLevel;
};


class Book {
public:
    Book(int id) : id(id) {}

    double calculate_fee(int day) const { return borrow_strategy->calculate(day); }

    int get_id() const { return id; }

    void setBorrowStrategy(std::shared_ptr<BorrowStrategy> strategy) { borrow_strategy = strategy; }

private:
    int id;
    std::shared_ptr<BorrowStrategy> borrow_strategy;
};

class Library {
public:
    using BookPtr = std::shared_ptr<Book>;

    void add_book(const BookPtr &book) {
        books[book->get_id()] = book;
    }

    void borrow_book(int id, const std::shared_ptr<BorrowStrategy> &strategy) {
        auto it = books.find(id);
        it->second->setBorrowStrategy(strategy);
        borrowed_books.push_back(it->second);
    }

    double return_books(int days) {
        double total_fee = 0.0;
        for (const auto &book: borrowed_books) total_fee += book->calculate_fee(days);
        borrowed_books.clear();
        return total_fee;
    }

private:
    std::unordered_map<int, BookPtr> books;
    std::vector<BookPtr> borrowed_books;
};

// === TEST_CASES ===
void TEST_1();

void TEST_2();

void TEST_3();

void TEST_4();

void TEST_5();

void TEST_6();

void TEST_7();

#define REGISTER_TEST_CASE(name) {#name, name}

int main() {
    std::unordered_map<std::string, std::function<void()> >
            test_functions_by_name = {
            REGISTER_TEST_CASE(TEST_1), REGISTER_TEST_CASE(TEST_2),
            REGISTER_TEST_CASE(TEST_3), REGISTER_TEST_CASE(TEST_4),
            REGISTER_TEST_CASE(TEST_5), REGISTER_TEST_CASE(TEST_6),
            REGISTER_TEST_CASE(TEST_7),
    };

    std::string test_case_name;
    std::cin >> test_case_name;
    auto it = test_functions_by_name.find(test_case_name);
    assert(it != test_functions_by_name.end());
    auto fn = it->second;
    fn();
    return 0;
}

void TEST_1() {
    Library library;

    library.add_book(std::make_shared<Book>(1));
    library.add_book(std::make_shared<Book>(2));

    library.borrow_book(1, std::make_shared<DailyBorrowStrategy>());

    assert(library.return_books(5) == 5.0);
}

void TEST_2() {
    Library library;

    library.add_book(std::make_shared<Book>(1));
    library.add_book(std::make_shared<Book>(2));

    library.borrow_book(2, std::make_shared<MemberBorrowStrategy>("GOLD"));

    assert(library.return_books(8) == 8.5);
}

void TEST_3() {
    Library library;

    library.add_book(std::make_shared<Book>(1));

    assert(library.return_books(0) == 0.0);
}

void TEST_4() {
    Library library;

    library.add_book(std::make_shared<Book>(1));
    library.add_book(std::make_shared<Book>(2));

    library.borrow_book(1, std::make_shared<DailyBorrowStrategy>());
    library.borrow_book(2, std::make_shared<MemberBorrowStrategy>("PLATINUM"));

    assert(library.return_books(10) == 17.5);
}

void TEST_5() {
    Library library;

    library.add_book(std::make_shared<Book>(1));
    library.add_book(std::make_shared<Book>(2));

    library.borrow_book(1, std::make_shared<DailyBorrowStrategy>());

    assert(library.return_books(5) == 5.0);

    library.borrow_book(2, std::make_shared<MemberBorrowStrategy>("REGULAR"));

    assert(library.return_books(7) == 4.75);
}

void TEST_6() {
    Library library;

    library.add_book(std::make_shared<Book>(1));
    library.add_book(std::make_shared<Book>(2));

    library.borrow_book(2, std::make_shared<MemberBorrowStrategy>("PLATINUM"));

    assert(library.return_books(14) == 7.5);
}

void TEST_7() {
    Library library;

    library.add_book(std::make_shared<Book>(1));
    library.add_book(std::make_shared<Book>(2));

    library.borrow_book(1, std::make_shared<DailyBorrowStrategy>());

    assert(library.return_books(5) == 5.0);

    assert(library.return_books(10000) == 0.0);
}