
#include "Author.h"
#include "Book.h"
#include <iostream>
#include <vector>

Author::Author()
        : Person(), book() {
    write_log();
}

Author::Author(string name, string surname, string last_name, Book book)
        : book{book}, Person(name, surname, last_name) {
    write_log();
}

Author::~Author() noexcept {
    ofstream foutLog(R"(D:\Coursework\Database\Logs.txt)",ios_base::app);
    auto now = chrono::system_clock::now();
    time_t log_time = chrono::system_clock::to_time_t(now);
    foutLog<<ctime(&log_time)<<"\t::\t"
    <<"Author object was deleted."<<endl;
}


ostream &operator<<(ostream &os, Author &obj) {
    os <<static_cast<const Person &>(obj)<< " ";
    os << obj.book << endl;
    return os;
}

istream &operator>>(istream &is, Author &obj) {
    is >> static_cast <Person &>(obj);
    is >> obj.book;
    return is;
}

Author::Author(const Author &other)
        : Person(other), book(other.book) {}

Author::Author(Author &&other)
        : Person(other), book(other.book) {
    other.name = "unknown";
    other.surname = "unknown";
    other.last_name = "unknown";
    other.book = Book();
}

string Author::getName() { return name; }

string Author::getSurname() { return surname; }

string Author::getLastName() { return last_name; }

[[maybe_unused]] void Author::getAuthor() const {
    cout << " " << name << " " << surname << " " << last_name << endl;
    book.getBook();
}

void Author::addBook(const Book &book) {
    if (this->book.getId() == book.getId()) {
        cerr << "This ID already exists" << endl;
        return;
    }
    this->book = book;
}

Book Author::getBook() const {
    return book;
}

string Author::getNameBook() {
    return book.getName();
}

double Author::getPriceBook() {
    return book.getPrice();
}

int Author::getId() {
    return book.getId();
}

void Author::setNameAuthor(const std::string &newName) {
    name = newName;
}

void Author::setSurnameAuthor(const std::string &newSurname) {
    surname = newSurname;
}

void Author::setLastNameAuthor(const std::string &newLastName) {
    last_name = newLastName;
}

void Author::setBookAuthor(const Book &newBook) {
    book = newBook;
}


void Author::write_log() {

    ofstream foutLog(R"(D:\Coursework\Database\Logs.txt)", ios_base::app);
    auto now = chrono::system_clock::now();
    time_t log_time = chrono::system_clock::to_time_t(now);
    foutLog << ctime(&log_time) << "\t::\t"
            << "Author object was created with parameters: " << endl
            << "\tname: " << name << endl
            << "\tsurname: " << surname << endl
            << "\tsurname: " << last_name << endl;
}










