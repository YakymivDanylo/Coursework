#include <iostream>
#include <stdexcept>
#include <limits>
#include <memory>
#include "fstream"
#include "ctime"
#include <vector>
#include "Reader.h"
#include "Bookstand.h"
#include "Author.h"
#include "Book.h"
#include "WrongChoice.h"
#include "WrongPassword.h"
#include "SameID.h"
#include "InvalidInputString.h"
#include "InvalidInputInt.h"
#include "WrongInputData.h"
#include "InvalidInput.h"
#include "BookIsInFile.h"
#include "chrono"
#include "FileReader.h"
#include "InstructionReader.h"

using namespace std;

void delimitation() {
    cout << "-------------------------------------------------------------" << endl;
}

void delimitation2() {
    cout << "===============================================================" << endl;
}

void addAuthorAndBook() {

    Book book0;
    Author author0;

    unique_ptr<string> name{new string{"unknown"}};
    cout << "Enter the author`s name: ";
    cin >> *name;
    if (cin.fail() || name->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }
    author0.setNameAuthor(*name);

    unique_ptr<string> surname{new string{"unknown"}};
    cout << "Enter the author`s surname: ";
    cin >> *surname;
    if (cin.fail() || surname->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }
    author0.setSurnameAuthor(*surname);


    unique_ptr<string> last_name{new string{"unknown"}};
    cout << "Enter the author`s last name: ";
    cin >> *last_name;
    if (cin.fail() || last_name->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }
    author0.setLastNameAuthor(*last_name);

    unique_ptr<string> bookName{new string{"unknown"}};
    cout << "Enter the book`s name: ";
    cin >> *bookName;
    if (cin.fail() || bookName->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }
    book0.setNameBook(*bookName);


    unique_ptr<double> bookPrice{new double{0.0}};
    cout << "Enter the book`s price: ";
    cin >> *bookPrice;
    book0.setPriceBook(*bookPrice);

    int bookID;
    srand(time(0));
    bookID = rand();

    book0.setIDBook(bookID);
    author0.setBookAuthor(book0);

    ifstream finB(R"(D:\Coursework\Database\Author+Book.txt)");

    unique_ptr<string> name1{new string{"unknown"}};

    unique_ptr<string> surname1{new string{"unknown"}};

    unique_ptr<string> last_name1{new string{"unknown"}};

    unique_ptr<string> bookName1{new string{"unknown"}};

    unique_ptr<double> bookPrice1{new double{0.0}};

    unique_ptr<int> bookID1{new int{0}};
    Book book1;
    Author author1;

    book1.setNameBook(*bookName1);
    book1.setPriceBook(*bookPrice1);
    book1.setIDBook(*bookID1);

    author1.setNameAuthor(*name1);
    author1.setSurnameAuthor(*surname1);
    author1.setLastNameAuthor(*last_name1);
    author1.setBookAuthor(book1);


    while (finB >> author1) {
        if (author0.getId() == author1.getId()) {
            throw SameID();
        }
    }
    finB.close();

    ofstream foutAB(R"(D:\Coursework\Database\Author+Book.txt)", ios_base::app);
    foutAB << author0.getName() << " " << author0.getSurname() << " " << author0.getLastName() << " "
           << author0.getNameBook() << " " << author0.getPriceBook() << " " << author0.getId()
           << endl;
    foutAB.close();
    ofstream foutB(R"(D:\Coursework\Database\Books.txt)", ios_base::app);
    foutB << author0.getNameBook() << " " << author0.getPriceBook() << " " << author0.getId() << endl;
    foutB.close();
    cout<<"Book was successfully added"<<endl;

}


void addBookstand() {

    unique_ptr<string> name{new string{"unknwon"}};

    unique_ptr<double> price{new double{0}};

    unique_ptr<int> id{new int{0}};

    unique_ptr<int> bookId{new int{0}};


    srand(time(0));
    int bookstandId = rand();


    cout << "Enter ID of the book: ";
    if (!(cin >> *bookId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputInt();
    }

    int counter = 0;
    int counter1 = 0;
    ifstream booksFile(R"(D:\Coursework\Database\Books.txt)");
    ifstream bookstandFile(R"(D:\Coursework\Database\Bookstands.txt)");
    ofstream foutbookstand(R"(D:\Coursework\Database\Bookstands.txt)", ios_base::app);

    if (booksFile.is_open()) {
        while (bookstandFile >> bookstandId >> *name >> *price >> *id) {
            if (*bookId == *id) {
                counter1++;
            }
        }
        bookstandFile.close();

        if (counter1 != 0) {
            cout << "This book is already in the bookstand!" << endl;
            cout << "Please change ID of the book which you want to add to the bookstand!" << endl;
        } else {

            while (booksFile >> *name >> *price >> *id) {
                if (*bookId == *id) {
                    Book book1;
                    Bookstand bookstand1;

                    book1.setNameBook(*name);
                    book1.setPriceBook(*price);
                    book1.setIDBook(*bookId);
                    bookstand1.setBookstandId(bookstandId);
                    bookstand1.setBook(book1);

                    foutbookstand << bookstand1 << endl;
                    counter++;
                }
            }
            booksFile.close();
            cout << "Book with ID:\t" << *bookId << "\twas successfully added" << endl;
            if (counter == 0) {
                cout << "There is no book with this ID!" << endl;
            }
        }

    } else {
        cerr << "Error opening file" << endl;
        return;
    }

}

void ShowBooks() {
    ifstream fin(R"(D:\Coursework\Database\Author+Book.txt)");
    ifstream finBookstand(R"(D:\Coursework\Database\Bookstands.txt)");
    unique_ptr<string> name{new string{"unknown"}};
    unique_ptr<string> nameOfBook{new string{"unknown"}};
    unique_ptr<string> surname{new string{"unknown"}};
    unique_ptr<string> last_name{new string{"unknown"}};
    unique_ptr<double> price{new double{0}};
    unique_ptr<int> id{new int{0}};
    unique_ptr<int> bookstandID{new int{0}};
    Book book(*nameOfBook, *price, *id);
    Author author(*name, *surname, *last_name, book);
    Bookstand bookstand(*bookstandID, book);
    int counter = 1;
    delimitation2();

    while (fin >> author) {
        cout << "Book number: " << counter++ << endl;
        cout << endl;
        cout << "Author`s name:" << "\t" << author.getName() << endl;
        cout << "Author`s surname:" << "\t" << author.getSurname() << endl;
        cout << "Author`s last name:" << "\t" << author.getLastName() << endl;
        cout << endl;
        cout << "Book`s name:" << "\t" << author.getNameBook() << endl;
        cout << "Book`s price:" << "\t" << author.getPriceBook() << endl;
        cout << "Book`s id:" << "\t" << author.getId() << endl;
        cout << endl;
        delimitation2();
    }
    fin.close();
}

void ShowBookstands() {
    ifstream fin(R"(D:\Coursework\Database\Bookstands.txt)");
    unique_ptr<string> name{new string{"unknown"}};
    unique_ptr<double> price{new double{0}};
    unique_ptr<int> id{new int{0}};
    unique_ptr<int> idBookstand{new int{0}};
    Book book(*name, *price, *id);
    Bookstand bookstand(*idBookstand, book);
    delimitation2();

    while (fin >> bookstand) {
        cout << "Bookstand with ID:" << "\t" << bookstand.getIdBookstand() << endl;
        cout << "Book`s name:" << "\t" << bookstand.getNameBook() << endl;
        cout << "Book`s price:" << "\t" << bookstand.getPriceBook() << endl;
        cout << "Book`s ID:" << "\t" << bookstand.getIdBook() << endl;
        delimitation2();
    }
    fin.close();
}

void ShowReaders() {
    ifstream fin(R"(D:\Coursework\Database\Reader.txt)");
    unique_ptr<string> nameReader{new string{"unknown"}};
    unique_ptr<string> surnameReader{new string{"unknown"}};
    unique_ptr<string> last_nameReader{new string{"unknown"}};
    unique_ptr<int> idReader{new int{0}};

    unique_ptr<string> nameAuthor{new string{"unknown"}};
    unique_ptr<string> surnameAuthor{new string{"unknown"}};
    unique_ptr<string> last_nameAuthor{new string{"unknown"}};

    unique_ptr<string> nameOfBook{new string{"unknown"}};
    unique_ptr<double> price{new double{0}};
    unique_ptr<int> idBook{new int{0}};
    int counter = 1;

    Book book(*nameOfBook, *price, *idBook);
    Author author(*nameAuthor, *surnameAuthor, *last_nameAuthor, book);
    Reader reader(*nameReader, *surnameReader, *last_nameReader, *idReader);
    delimitation2();
    while (fin >> reader >> author) {
        cout << "Reader number: " << counter++ << endl;
        cout << endl;
        cout << "Reader`s name:" << "\t" << reader.getName() << endl;
        cout << "Reader`s surname:" << "\t" << reader.getSurname() << endl;
        cout << "Reader`s last name:" << "\t" << reader.getLastName() << endl;
        cout << "Reader`s ID:" << "\t" << reader.getID() << endl;
        cout << endl;
        cout << "Author`s name:" << "\t" << author.getName() << endl;
        cout << "Author`s surname:" << "\t" << author.getLastName() << endl;
        cout << "Author`s last name:" << "\t" << author.getSurname() << endl;
        cout << endl;
        cout << "Book`s name:" << "\t" << author.getNameBook() << endl;
        cout << "Book`s price:" << "\t" << author.getPriceBook() << endl;
        cout << "Book`s ID:" << "\t" << author.getId() << endl;
        delimitation2();
    }

    fin.close();
}


int ShowBookById() {
    Book book1;
    Reader reader;
    Author author;
    int bookId;
    cout << "Enter ID of the book: ";
    if (!(cin >> bookId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInput();
    }

    unique_ptr<Book> book = book1.findBookById(R"(D:\Coursework\Database\Books.txt)", bookId);
    if (book) {
        cout << "Here is your book:" << endl;
        cout << "Book`s name:" << "\t" << book->getName() << endl;
        cout << "Book`s price:" << "\t" << book->getPrice() << endl;
        cout << "Book`s ID:" << "\t" << book->getId() << endl;
    } else {
        cout << "Book with this ID was not found" << endl;

        unique_ptr<string> name{new string{"unknown"}};
        unique_ptr<string> surname{new string{"unknown"}};
        unique_ptr<string> last_name{new string{"unknown"}};
        unique_ptr<int> idR{new int{0}};

        Reader reader1(*name, *surname, *last_name, *idR);

        unique_ptr<string> nameOfBook{new string{"unknown"}};
        unique_ptr<double> price{new double{0}};
        unique_ptr<int> id{new int{0}};

        Book book3(*nameOfBook, *price, *id);

        unique_ptr<string> nameAu{new string{"unknown"}};
        unique_ptr<string> surnameAu{new string{"unknown"}};
        unique_ptr<string> last_nameAu{new string{"unknown"}};

        Author author1(*nameAu, *surnameAu, *last_nameAu, book3);

        ifstream finR(R"(D:\Coursework\Database\Reader.txt)");

        while (finR >> reader1 >> author1) {
            if (bookId == author1.getId()) {
                Book book2(*nameOfBook, *price, bookId);
                Author author2(*nameAu, *surnameAu, *last_nameAu, book2);
                cout << "This book was taken by:" << endl;
                delimitation2();
                cout << "Reader`s name:" << "\t" << reader1.getName() << endl;
                cout << "Reader`s surname:" << "\t" << reader1.getSurname() << endl;
                cout << "Reader`s last name:" << "\t" << reader1.getLastName() << endl;
                cout << "Reader`s ID:" << "\t" << reader1.getID() << endl;
                cout << endl;
                cout << "Author`s name:" << "\t" << author1.getName() << endl;
                cout << "Author`s surname:" << "\t" << author1.getSurname() << endl;
                cout << "Author`s last name:" << "\t" << author1.getLastName() << endl;
                cout << endl;
                cout << "Book`s name:" << "\t" << author1.getNameBook() << endl;
                cout << "Book`s price:" << "\t" << author1.getPriceBook() << endl;
                cout << "Book`s ID:" << "\t" << author1.getId() << endl;
                delimitation2();
            }
        }

    }

    return 0;
}

void ShowBooksByAuthor() {
    unique_ptr<string> name{new string{"unknown"}};
    unique_ptr<string> surname{new string{"unknown"}};
    unique_ptr<string> last_name{new string{"unknown"}};
    cout << "Enter author`s name: ";
    cin >> *name;
    if (cin.fail() || name->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInput();
    }
    cout << "Enter author`s surname: ";
    cin >> *surname;
    if (cin.fail() || surname->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInput();
    }
    cout << "Enter author`s last name: ";
    cin >> *last_name;
    if (cin.fail() || last_name->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInput();
    }
    cout<<endl;
    delimitation2();
    ifstream finAB(R"(D:\Coursework\Database\Author+Book.txt)");
    Book book;
    Author author;
    int counter = 0;
    int counterBook = 1;
    while (finAB >> author) {
        if (*name == author.getName() && *surname == author.getSurname() && *last_name == author.getLastName()) {
            book = author.getBook();
            cout << "Book number:\t" << counterBook++ << endl;
            cout << endl;
            cout << "Book`s name:\t" << book.getName() << endl;
            cout << "Book`s price:\t" << book.getPrice() << endl;
            cout << "Book`s ID:\t" << book.getId() << endl;
            counter++;
        }
    }
    finAB.close();
    delimitation2();
    if (counter == 0) {
        cerr << "There is no author with this name!" << endl;
        cerr << "Check if you entered the name correctly!" << endl;
    }
}

void showMyBooks() {
    cout << "You need to log in" << endl;

    unique_ptr<string> name{new string{"unknown"}};
    unique_ptr<string> surname{new string{"unknown"}};
    unique_ptr<string> last_name{new string{"unknown"}};
    unique_ptr<int> idR{new int{0}};

    unique_ptr<string> name2{new string{"unknown"}};
    unique_ptr<string> surname2{new string{"unknown"}};
    unique_ptr<string> last_name2{new string{"unknown"}};
    unique_ptr<int> idR2{new int{0}};


    unique_ptr<string> nameOfBook{new string{"unknown"}};
    unique_ptr<double> price{new double{0}};
    unique_ptr<int> id{new int{0}};


    unique_ptr<string> nameAu{new string{"unknown"}};
    unique_ptr<string> surnameAu{new string{"unknown"}};
    unique_ptr<string> last_nameAu{new string{"unknown"}};


    cout << "Enter your name: ";
    cin >> *name;
    if (cin.fail() || name->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }
    cout << "Enter your surname: ";
    cin >> *surname;
    if (cin.fail() || surname->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }

    cout << "Enter your last name: ";
    cin >> *last_name;
    if (cin.fail() || last_name->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }
    cout << "Enter your ID: ";

    if (!(cin >> *idR)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputInt();
    }
    cout << endl;
    ifstream finR(R"(D:\Coursework\Database\Reader.txt)");
    Book book;
    Author author;
    Reader reader;
    int counter = 0;
    int counterBook = 1;

    Reader enterReader(*name, *surname, *last_name, *idR);
    Reader readReader(*name2, *surname2, *last_name2, *idR2);
    Book book1(*nameOfBook, *price, *id);
    Author author1(*nameAu, *surnameAu, *last_nameAu, book);


    while (finR >> readReader >> author1) {
        delimitation2();
        if (enterReader.getName() == readReader.getName() && enterReader.getSurname() == readReader.getSurname() &&
            enterReader.getLastName() == readReader.getLastName() && enterReader.getID() == readReader.getID()) {

            cout << "Book number:" << "\t" << counterBook++ << endl;
            cout << endl;
            cout << "Author`s name:" << "\t" << author1.getName() << endl;
            cout << "Author`s surname:" << "\t" << author1.getSurname() << endl;
            cout << "Author`s last name:" << "\t" << author1.getLastName() << endl;
            cout << endl;
            cout << "Book`s name:" << "\t" << author1.getNameBook() << endl;
            cout << "Book`s price:" << "\t" << author1.getPriceBook() << endl;
            cout << "Book`s ID:" << "\t" << author1.getId() << endl;
            delimitation2();
            counter++;
        }
    }
    finR.close();
    if (counter == 0) {
        cerr << "There is no reader with this name!" << endl;
        cerr << "Check if you entered the name correctly!" << endl;

    }
}

void takeBook() {
    string filenameAuthor = R"(D:\Coursework\Database\Author+Book.txt)";
    string filenameBook = R"(D:\Coursework\Database\Books.txt)";
    string filenameBookstand = R"(D:\Coursework\Database\Bookstands.txt)";
    string filenameReader = R"(D:\Coursework\Database\Reader.txt)";


    cout << "You need to log in" << endl;
    unique_ptr<string> name{new string{" "}};
    unique_ptr<string> surname{new string{" "}};
    unique_ptr<string> last_name{new string{" "}};
    unique_ptr<int> idR{new int{0}};

    unique_ptr<string> nameAu{new string{" "}};
    unique_ptr<string> surnameAu{new string{" "}};
    unique_ptr<string> last_nameAu{new string{" "}};

    unique_ptr<string> nameOfBook{new string{" "}};
    unique_ptr<double> price{new double{0.0}};
    unique_ptr<int> id{new int{0}};
    unique_ptr<int> idOfBook{new int{0}};

    unique_ptr<int> idBs{new int{0}};

    cout << "Enter your name: ";
    cin >> *name;
    if (cin.fail() || name->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }
    cout << "Enter your surname: ";
    cin >> *surname;
    if (cin.fail() || surname->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }
    cout << "Enter your last name: ";
    cin >> *last_name;
    if (cin.fail() || last_name->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }
    cout << "Create your own ID and remember it!\n If you have one enter it.\n";
    cout << "Enter your ID:";
    if (!(cin >> *idR)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputInt();
    }

    cout << "Enter book`s ID which you want to take: ";
    if (!(cin >> *idOfBook)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputInt();
    }

    Reader reader1(*name, *surname, *last_name, *idR);

    ifstream finAuthor(filenameAuthor);
    while (finAuthor >> *nameAu >> *surnameAu >> *last_nameAu >> *nameOfBook >> *price >> *id) {
        if (*idOfBook == *id) {

            Book book(*nameOfBook, *price, *idOfBook);
            Author author(*nameAu, *surnameAu, *last_nameAu, book);
            Reader reader(*name, *surname, *last_name, *idR);

            ofstream foutReader(filenameReader, ios_base::app);
            foutReader << reader.getName() << " " << reader.getSurname() << " " << reader.getLastName() << " "
                       << reader.getID() << " " << author.getName() << " " << author.getSurname() << " "
                       << author.getLastName() << " " << author.getNameBook() << " " << author.getPriceBook() << " "
                       << author.getId() << endl;
            foutReader.close();
        }

    }

    finAuthor.close();

    ifstream finAuthor1(filenameAuthor);
    ofstream foutAuthor("tempAuthor.txt");
    while (finAuthor1 >> *nameAu >> *surnameAu >> *last_nameAu >> *nameOfBook >> *price >> *id) {
        if (*idOfBook != *id) {

            Book book(*nameOfBook, *price, *id);
            Author author(*nameAu, *surnameAu, *last_nameAu, book);
            foutAuthor << author.getName() << " " << author.getSurname() << " " << author.getLastName() << " "
                       << author.getNameBook() << " " << author.getPriceBook() << " " << author.getId() << endl;
        }
    }
    foutAuthor.close();
    finAuthor1.close();

    remove(filenameAuthor.c_str());
    rename("tempAuthor.txt", filenameAuthor.c_str());


    ifstream finBook(filenameBook);
    ofstream foutBook("tempBook.txt");
    while (finBook >> *nameOfBook >> *price >> *id) {
        if (*idOfBook != *id) {
            Book book(*nameOfBook, *price, *id);

            foutBook << book.getName() << " " << book.getPrice() << " " << book.getId() << endl;
        }
    }
    foutBook.close();
    finBook.close();

    remove(filenameBook.c_str());
    rename("tempBook.txt", filenameBook.c_str());


    ifstream finBookstand(filenameBookstand);
    ofstream foutBookstand("tempBookstand.txt");
    while (finBookstand >> *idBs >> *nameOfBook >> *price >> *id) {
        if (*idOfBook != *id) {
            Book book(*nameOfBook, *price, *id);
            Bookstand bookstand(*idBs, book);
            foutBookstand << bookstand.getIdBookstand() << " " << bookstand.getNameBook() << " "
                          << bookstand.getPriceBook() << " " << bookstand.getIdBook() << endl;
        }
    }
    foutBookstand.close();
    finBookstand.close();

    remove(filenameBookstand.c_str());
    rename("tempBookstand.txt", filenameBookstand.c_str());


    cout << "Book with ID " << *idOfBook << " was taken by " << reader1.getName() << " " << reader1.getSurname() << " "
         << reader1.getLastName() << "  "
         << reader1.getID() << endl;

}

void returnBook() {
    string filenameAuthor = R"(D:\Coursework\Database\Author+Book.txt)";
    string filenameBook = R"(D:\Coursework\Database\Books.txt)";
    string filenameReader = R"(D:\Coursework\Database\Reader.txt)";

    unique_ptr<string> name{new string{" "}};
    unique_ptr<string> surname{new string{" "}};
    unique_ptr<string> last_name{new string{" "}};

    unique_ptr<string> name2{new string{" "}};
    unique_ptr<string> surname2{new string{" "}};
    unique_ptr<string> last_name2{new string{" "}};

    unique_ptr<string> nameAu{new string{" "}};
    unique_ptr<string> surnameAu{new string{" "}};
    unique_ptr<string> last_nameAu{new string{" "}};

    unique_ptr<string> nameOfBook{new string{" "}};
    unique_ptr<double> price{new double{0.0}};
    unique_ptr<int> id{new int{0}};
    unique_ptr<int> idOfBook{new int{0}};

    unique_ptr<int> idR{new int{0}};
    unique_ptr<int> idR2{new int{0}};

    cout << "Enter your name: ";
    cin >> *name;
    if (cin.fail() || name->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }

    cout << "Enter your surname: ";
    cin >> *surname;
    if (cin.fail() || surname->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }

    cout << "Enter your last name: ";
    cin >> *last_name;
    if (cin.fail() || last_name->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }

    cout << "Enter your ID: ";
    cin >> *idR;
    if (!(cin >> *idR)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputInt();
    }

    cout << "Enter book`s ID which you want to return: ";
    cin >> *idOfBook;
    if (!(cin >> *idOfBook)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputInt();
    }

    ifstream finReader(filenameReader);
    while (finReader >> *name >> *surname >> *last_name >> *idR2 >> *nameAu >> *surnameAu >> *last_nameAu >> *nameOfBook
                     >> *price >> *id) {
        if (*idOfBook == *id && *idR == *idR2) {

            Book book(*nameOfBook, *price, *idOfBook);

            ofstream foutBook(filenameBook, ios_base::app);
            foutBook << book.getName() << " " << book.getPrice() << " " << book.getId() << endl;
            foutBook.close();

            Author author(*nameAu, *surnameAu, *last_nameAu, book);
            ofstream foutAuthor(filenameAuthor, ios_base::app);
            foutAuthor << author.getName() << " " << author.getSurname() << " " << author.getLastName() << " "
                       << author.getNameBook() << " " << author.getPriceBook()
                       << " " << author.getId() << endl;
            foutAuthor.close();
        }
    }
    finReader.close();


    ifstream finReader1(filenameReader);
    ofstream foutReader("tempReader.txt");
    while (finReader1 >> *name >> *surname >> *last_name >> *idR2 >> *nameAu >> *surnameAu >> *last_nameAu
                      >> *nameOfBook >> *price >> *id) {
        if (*idOfBook != *id) {
            Reader reader(*name, *surname, *last_name, *idR2);
            Book book(*nameOfBook, *price, *id);
            Author author(*nameAu, *surnameAu, *last_nameAu, book);

            foutReader << reader.getName() << " " << reader.getSurname() << " " << reader.getLastName() << " "
                       << reader.getID() << " " << author.getName() << " "
                       << author.getSurname() << " " << author.getLastName() << " " << author.getNameBook() << " "
                       << author.getPriceBook() << " " << author.getId()
                       << endl;
        }
    }
    foutReader.close();
    finReader1.close();

    remove(filenameReader.c_str());
    rename("tempReader.txt", filenameReader.c_str());

    cout << "Book with ID " << *idOfBook<< " was successfully returned" << endl;



}

struct ReaderData {
    string nameAuthor, surnameAuthor, last_nameAuthor, nameBook;
    string nameReader, surnameReader, last_nameReader;
    int idBook, idReader;
    double priceBook;
};

void changeReader() {
    unique_ptr<string> name{new string{"unknown"}};
    unique_ptr<string> surname{new string{"unknown"}};
    unique_ptr<string> last_name{new string{"unknown"}};
    unique_ptr<int> idReader{new int{0}};

    cout << "Enter your name: ";
    cin >> *name;
    if (cin.fail() || name->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }

    cout << "Enter your surname: ";
    cin >> *surname;
    if (cin.fail() || surname->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }

    cout << "Enter your last name: ";
    cin >> *last_name;
    if (cin.fail() || last_name->find_first_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputString();
    }

    cout << "Enter your ID: ";
    cin >> *idReader;
    if (!(cin >> *idReader)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputInt();
    }
    vector<ReaderData> readers;
    ifstream finReader(R"(D:\Coursework\Database\Reader.txt)");

    if (!finReader.is_open()) {
        cerr << "Error opening file: Reader.txt" << endl;
        return;
    }
    string line;
    while (getline(finReader, line)) {
        istringstream iss(line);
        ReaderData reader;
        iss >> reader.nameReader >> reader.surnameReader >> reader.last_nameReader >> reader.idReader
            >> reader.nameAuthor >> reader.surnameAuthor >> reader.last_nameAuthor >> reader.nameBook
            >> reader.priceBook >> reader.idBook;
        readers.push_back(reader);
    }
    finReader.close();
    cout<<endl;
    bool found = false;
    for (ReaderData &reader: readers) {
        if (reader.idReader == *idReader && reader.nameReader == *name && reader.surnameReader == *surname &&
            reader.last_nameReader == *last_name) {
            found = true;
            delimitation2();
            cout << "Current information for reader with ID " << *idReader << ":" << endl;
            cout << "Reader`s name: " << reader.nameReader << endl;
            cout << "Reader`s surname: " << reader.surnameReader << endl;
            cout << "Reader`s last name: " << reader.last_nameReader << endl;
            cout<<endl;
            cout << "Author`s name: " << reader.nameAuthor << endl;
            cout << "Author`s surname: " << reader.surnameAuthor << endl;
            cout << "Author`s last name: " << reader.last_nameAuthor << endl;
            cout<<endl;
            cout << "Book`s name: " << reader.nameBook << endl;
            cout << "Book`s price: " << reader.priceBook << endl;
            cout << "Book`s ID: " << reader.idBook << endl;
            cout<<endl;
            while (true) {
                delimitation2();
                cout << "What field do you want to change?" << endl;
                cout << "1.Reader`s name" << endl;
                cout << "2.Reader`s surname" << endl;
                cout << "3.Reader`s last name" << endl;
                cout << "0.Exit" << endl;

                int choice;
                if (!(cin >> choice)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw InvalidInputInt();
                }
                switch (choice) {
                    case 1: {
                        cout << "Enter new name: ";
                        cin >> reader.nameReader;
                        break;
                    }
                    case 2: {
                        cout << "Enter new surname: ";
                        cin >> reader.surnameReader;
                        break;
                    }
                    case 3: {
                        cout << "Enter new last name: ";
                        cin >> reader.last_nameReader;
                        break;
                    }
                    case 0:{
                        ofstream foutReader(R"(D:\Coursework\Database\Reader.txt)",ios::out | ios::trunc);
                        if (!foutReader.is_open()) {
                            cerr << "Error opening file: Reader.txt" << endl;
                            return;
                        }

                        for(const ReaderData &reader : readers){
                            foutReader << reader.nameReader << " " << reader.surnameReader << " " <<reader.last_nameReader<<" "<<reader.idReader<<" "<<reader.nameAuthor<<" "<<reader.surnameAuthor<<" "<<reader.last_nameAuthor<<" "<<reader.nameBook<<" "<<reader.priceBook<<" "<<reader.idBook<<endl;
                        }
                        foutReader.close();
                        cout<<"Updated information for reader with ID "<< reader.idReader<<":"<<endl;
                        cout << "Reader`s name: " << reader.nameReader << endl;
                        cout << "Reader`s surname: " << reader.surnameReader << endl;
                        cout << "Reader`s last name: " << reader.last_nameReader << endl;
                        cout << "Author`s name: " << reader.nameAuthor << endl;
                        cout << "Author`s surname: " << reader.surnameAuthor << endl;
                        cout << "Author`s last name: " << reader.last_nameAuthor << endl;
                        cout << "Book`s name: " << reader.nameBook << endl;
                        cout << "Book`s price: " << reader.priceBook << endl;
                        cout << "Book`s ID: " << reader.idBook << endl;
                    }
                        return;
                    default:
                        cout<<"Invalid input!"<<endl;
                }
            }
        }
    }
    if (!found) {
        cout << "Reader with ID " << *idReader << " not found." << endl;
    }
    delimitation();
}

struct AuthorBookData {
    string nameAuthor, surnameAuthor, last_nameAuthor, nameBook;
    double priceBook;
    int idBook;
    int idBookstand;
};

bool comparePriceAsc(const AuthorBookData &a, const AuthorBookData &b){
    return a.priceBook < b.priceBook;
}

bool comparePriceDesc(const AuthorBookData &a, const AuthorBookData &b){
    return a.priceBook > b.priceBook;
}

void sortBookByPriceAsc(){
    vector<AuthorBookData> books;
    ifstream fin(R"(D:\Coursework\Database\Author+Book.txt)");

    if(!fin.is_open()){
        cerr << "Error opening file: Author+Book.txt" << endl;
        return;
    }

    string line;
    while(getline(fin, line)){
        istringstream iss(line);
        AuthorBookData book;
        iss>>book.nameAuthor>>book.surnameAuthor>>book.last_nameAuthor>>book.nameBook>>book.priceBook>>book.idBook;
        books.push_back(book);
    }
    fin.close();

    sort(books.begin(), books.end(), comparePriceAsc);
    cout<<"Books sorted by price in ascending order:"<<endl;
    for(const AuthorBookData& book: books){
        cout<<book.nameAuthor << " " << book.surnameAuthor << " "
            << book.last_nameAuthor << " - " << book.nameBook << " ($"
            << book.priceBook << ")" << endl;
    }
}

void sortBooksByPriceDesc(){
    vector<AuthorBookData> books;
    ifstream fin(R"(D:\Coursework\Database\Author+Book.txt)");

    if(!fin.is_open()){
        cerr << "Error opening file: Author+Book.txt" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) {
        istringstream iss(line);
        AuthorBookData book;
        iss >> book.nameAuthor >> book.surnameAuthor >> book.last_nameAuthor
            >> book.nameBook >> book.priceBook >> book.idBook;
        books.push_back(book);
    }
    fin.close();
    sort(books.begin(), books.end(), comparePriceDesc);
    cout << "Books sorted by price in descending order:" << endl;
    for (const AuthorBookData& book : books) {
        cout << book.nameAuthor << " " << book.surnameAuthor << " "
             << book.last_nameAuthor << " - " << book.nameBook << " ($"
             << book.priceBook << ")" << endl;
    }
}
void deleteBook(int IdBook) {
    vector<AuthorBookData> authors;
    ifstream finAuthorBook(R"(D:\Coursework\Database\Author+Book.txt)");

    if (!finAuthorBook.is_open()) {
        cerr << "Error opening file: Author+Book.txt" << endl;
        return;
    }

    string line;
    while (getline(finAuthorBook, line)) {
        istringstream iss(line);
        AuthorBookData author;
        iss >> author.nameAuthor >> author.surnameAuthor >> author.last_nameAuthor >> author.nameBook >> author.priceBook >> author.idBook;
        authors.push_back(author);
    }
    finAuthorBook.close();

    // Find the index of the book to delete
    auto it = find_if(authors.begin(), authors.end(),
                      [IdBook](const AuthorBookData& a) { return a.idBook == IdBook; });

    if (it != authors.end()) {
        authors.erase(it); // Delete the book if found

        ofstream foutAuthor(R"(D:\Coursework\Database\Author+Book.txt)", ios::out | ios::trunc);
        if (!foutAuthor.is_open()) {
            cerr << "Error opening file: Author+Book.txt" << endl;
            return;
        }

        for (const AuthorBookData& author : authors) {
            foutAuthor << author.nameAuthor << " " << author.surnameAuthor << " "
                       << author.last_nameAuthor << " " << author.nameBook << " "
                       << author.priceBook << " " << author.idBook << endl;
        }
        foutAuthor.close();

        cout << "Book with ID " << IdBook << " was successfully deleted." << endl;
    } else {
        cout << "Book with ID " << IdBook << " not found." << endl;
    }
}

void changeAuthorBook() {
    unique_ptr<int> idBook{new int{0}};
    cout << "Enter ID of the book which you want to change: ";
    if (!(cin >> *idBook)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputInt();
    }

    vector<AuthorBookData> author_book;
    ifstream finAuthorBook(R"(D:\Coursework\Database\Author+Book.txt)");
    if (!finAuthorBook.is_open()) {
        cerr << "Error opening file: Author+Book.txt" << endl;
        return;
    }
    string line;
    while (getline(finAuthorBook, line)) {
        istringstream iss(line);
        AuthorBookData authors;
        iss >> authors.nameAuthor >> authors.surnameAuthor >> authors.last_nameAuthor >> authors.nameBook
            >> authors.priceBook >> authors.idBook;
        author_book.push_back(authors);
    }
    finAuthorBook.close();
    bool found = false;
    for (AuthorBookData &authors: author_book) {
        if (authors.idBook == *idBook) {
            found = true;
            delimitation2();
            cout << "Current inforamtion for the author and his book with ID " << *idBook << ":" << endl;
            cout << "Author`s name: " << authors.nameAuthor << endl;
            cout << "Author`s surname: " << authors.surnameAuthor << endl;
            cout << "Author`s last name: " << authors.last_nameAuthor << endl;
            cout << "Book`s name: " << authors.nameBook << endl;
            cout << "Book`s price: " << authors.priceBook << endl;
            cout << "Book`s ID: " << authors.idBook << endl;
            delimitation2();
            while (true) {
                delimitation2();
                cout << "Choose what field do you want to change?" << endl;
                cout << "1. Author`s name" << endl;
                cout << "2. Author`s surname" << endl;
                cout << "3. Author`s last name" << endl;
                cout << "4. Book`s name" << endl;
                cout << "5. Book`s price" << endl;
                cout << "6. Book`s ID" << endl;
                cout << "0. Exit" << endl;
                delimitation2();
                int choice;
                if (!(cin >> choice)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw InvalidInputInt();
                }

                switch (choice) {
                    case 1: {
                        cout << "Enter new name: ";
                        cin >> authors.nameAuthor;
                        if (cin.fail() || authors.nameAuthor.find_first_of("0123456789") != string::npos) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw InvalidInputString();
                        }
                        break;
                    }
                    case 2: {
                        cout << "Enter new surname: ";
                        cin >> authors.surnameAuthor;
                        if (cin.fail() || authors.surnameAuthor.find_first_of("0123456789") != string::npos) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw InvalidInputString();
                        }
                        break;
                    }
                    case 3: {
                        cout << "Enter new last name: ";
                        cin >> authors.last_nameAuthor;
                        if (cin.fail() || authors.last_nameAuthor.find_first_of("0123456789") != string::npos) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw InvalidInputString();
                        }
                        break;
                    }
                    case 4: {
                        cout << "Enter new book`s name: ";
                        cin >> authors.nameBook;
                        if (cin.fail() || authors.nameBook.find_first_of("0123456789") != string::npos) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw InvalidInputString();
                        }
                        break;
                    }
                    case 5: {
                        cout << "Enter new book`s price: ";
                        if (!(cin >> authors.priceBook)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw InvalidInputInt();
                        }
                        break;
                    }
                    case 6: {
                        cout << "Enter new book`s ID: ";
                        if (!(cin >> authors.idBook)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw InvalidInputInt();
                        }
                        break;
                    }
                    case 0: {
                        ofstream foutAuthorBook(R"(D:\Coursework\Database\Author+Book.txt)", ios::out | ios::trunc);
                        ofstream foutBook(R"(D:\Coursework\Database\Books.txt)", ios::out | ios::trunc);
                        ofstream foutBookstand(R"(D:\Coursework\Database\Bookstands.txt)", ios::out | ios::trunc);
                        if (!foutAuthorBook.is_open()) {
                            cerr << "Error opening file: Author+Book.txt" << endl;
                            return;
                        }
                        if (!foutBook.is_open()) {
                            cerr << "Error opening file: Book.txt" << endl;
                            return;
                        }
                        if (!foutBookstand.is_open()) {
                            cerr << "Error opening file: Bookstand.txt" << endl;
                            return;
                        }

                        for (const AuthorBookData &authors: author_book) {
                            foutAuthorBook << authors.nameAuthor << " " << authors.surnameAuthor << " "
                                           << authors.last_nameAuthor << " " << authors.nameBook << " "
                                           << authors.priceBook << " " << authors.idBook << endl;
                            foutBook << authors.nameBook << " " << authors.priceBook << " " << authors.idBook << endl;
                            foutBookstand << authors.idBookstand << " " << authors.nameBook << " " << authors.priceBook
                                          << " " << authors.idBook << endl;
                        }
                        foutAuthorBook.close();
                        foutBook.close();
                        foutBookstand.close();
                        cout << "Updated information for author and book with ID " << *idBook << ":" << endl;
                        cout << "Author`s name: " << authors.nameAuthor << endl;
                        cout << "Author`s surname: " << authors.surnameAuthor << endl;
                        cout << "Author`s last name: " << authors.last_nameAuthor << endl;
                        cout << "Book`s name: " << authors.nameBook << endl;
                        cout << "Book`s price: " << authors.priceBook << endl;
                        cout << "Book`s ID: " << authors.idBook << endl;
                    }
                        return;
                    default: {
                        cout << "Invalid choice!" << endl;
                    }
                }

            }

        }
    }
    if (!found) {
        cout << "Author and book with ID " << *idBook << " not found." << endl;
    }
    delimitation();
}

void filterBooksByPriceRange() {
    double minPrice, maxPrice;

    cout << "Enter the minimum price: ";
    if (!(cin >> minPrice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputInt();
    }

    cout << "Enter the maximum price: ";
    if (!(cin >> maxPrice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputInt();
    }

    vector<AuthorBookData> books;
    ifstream fin(R"(D:\Coursework\Database\Author+Book.txt)");

    if (!fin.is_open()) {
        cerr << "Error opening file: Author+Book.txt" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        istringstream iss(line);
        AuthorBookData book;
        iss >> book.nameAuthor >> book.surnameAuthor >> book.last_nameAuthor
            >> book.nameBook >> book.priceBook >> book.idBook;
        books.push_back(book);
    }
    fin.close();

    cout << "Books within the price range $" << minPrice << " - $" << maxPrice << ":" << endl;
    bool found = false;
    for (const AuthorBookData& book : books) {
        if (book.priceBook >= minPrice && book.priceBook <= maxPrice) {
            cout << book.nameAuthor << " " << book.surnameAuthor << " "
                 << book.last_nameAuthor << " - " << book.nameBook << " ($"
                 << book.priceBook << ")" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No books found within the specified price range." << endl;
    }
}

int main() {

    try {
        delimitation();
        cout << "Welcome to our library" << endl;
        while (true) {
            cout << "Choose what you want to do: " << endl;
            cout << "1. Administrator" << endl;
            cout << "2. Reader" << endl;
            cout << "3. Instruction" << endl;
            cout << "0. Exit" << endl;
            delimitation();
            int choice;
            cin >> choice;
            if (cin.fail()) {
                throw InvalidInput();
            }
            delimitation();

            if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
                throw WrongChoice();
            switch (choice) {//Admin
                case 1: {
                    string password;
                    int k = 0;
                    while (k < 3) {
                        cout << endl;
                        cout << "Enter password" << endl;
                        cin >> password;
                        delimitation();
                        if (password == "123") {
                            try {
                                cout << "Successful access!" << endl;
                                while (true) {
                                    cout << "Choose what you want to do." << endl;
                                    cout << "1. Add the book." << endl;
                                    cout << "2. Add the book to the bookstand." << endl;
                                    cout << "3. Show books." << endl;
                                    cout << "4. Show readers." << endl;
                                    cout << "5. Show book by its ID." << endl;
                                    cout << "6. Show bookstands." << endl;
                                    cout << "7. Show books by author`s full name." << endl;
                                    cout << "8. Delete book by its ID." << endl;
                                    cout << "9. Change author and its book by ID." << endl;
                                    cout << "10. Sort books by price in ascending order." << endl;
                                    cout << "11. Sort books by price in descending order." << endl;
                                    cout << "12. Filter books by price range." << endl;
                                    cout << "0. Exit." << endl << endl;
                                    int choiceAd;
                                    cin >> choiceAd;
                                    delimitation();
                                    if (cin.fail()) {
                                        throw InvalidInput();
                                    }
                                    if (choiceAd != 1 && choiceAd != 2 && choiceAd != 3 && choiceAd != 0 &&
                                        choiceAd != 4 &&
                                        choiceAd != 5 && choiceAd != 6 && choiceAd != 7 && choiceAd != 8 &&
                                        choiceAd != 9 && choiceAd != 10 && choiceAd != 11 && choiceAd != 12)
                                        throw WrongChoice();
                                    switch (choiceAd) {
                                        case 1: {
                                            addAuthorAndBook();
                                            delimitation();
                                            break;
                                        }
                                        case 2: {
                                            addBookstand();
                                            delimitation();
                                            break;
                                        }
                                        case 3: {
                                            ShowBooks();
                                            delimitation();
                                            break;
                                        }
                                        case 4: {
                                            ShowReaders();
                                            delimitation();
                                            break;
                                        }
                                        case 5: {
                                            ShowBookById();
                                            delimitation();
                                            break;

                                        }
                                        case 6: {
                                            ShowBookstands();
                                            delimitation();
                                            break;

                                        }
                                        case 7: {
                                            ShowBooksByAuthor();
                                            delimitation();
                                            break;

                                        }
                                        case 8: {
                                            int idBook;
                                            cout << "Enter ID of the book which you want to delete: ";
                                            if (!(cin >> idBook)) {
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                throw InvalidInputInt();
                                            }
                                            deleteBook(idBook);
                                            delimitation();
                                            break;
                                        }
                                        case 9: {
                                            changeAuthorBook();
                                            delimitation();
                                            break;
                                        }
                                        case 10: {
                                            sortBookByPriceAsc();
                                            delimitation();
                                            break;
                                        }
                                        case 11: {
                                            sortBooksByPriceDesc();
                                            delimitation();
                                            break;
                                        }
                                        case 12: {
                                            filterBooksByPriceRange();
                                            delimitation();
                                            break;
                                        }
                                        case 0: {
                                            delimitation();
                                            return 0;
                                        }
                                        default: {
                                            cout << endl;
                                            throw WrongChoice();
                                        }
                                    }
                                }
                            }
                            catch (WrongChoice &Choice) {
                                cerr << Choice.what();
                            }
                            catch (SameID &ID) {
                                cerr << ID.what();
                            }

                        } else {
                            cout << "Wrong password !" << endl;
                            cout << "Check what you entered !" << endl;
                            delimitation();
                            k++;
                        }
                    }
                    if (k == 3) {
                        cout << "You have reached the maximum number of attempts! The program ends!" << endl;
                        delimitation();
                        return 1;
                    }
                    break;
                }
                case 2: {
                    cout << "Welcome" << endl;
                    while (true) {
                        cout << "Choose what you want to do " << endl;
                        cout << "1. Show Books " << endl;
                        cout << "2. Show books by author`s full name " << endl;
                        cout << "3. Take a book " << endl;
                        cout << "4. Return a book " << endl;
                        cout << "5. Show my books " << endl;
                        cout << "6. Change my information " << endl;
                        cout << "7. Sort books by price in ascending order." << endl;
                        cout << "8. Sort books by price in descending order." << endl;
                        cout << "9. Filter books by price range." << endl;
                        cout << "0. Exit " << endl;
                        delimitation();
                        cout<<endl;
                        int choiceC;
                        cin >> choiceC;
                        delimitation();
                        if (cin.fail()) {
                            throw InvalidInput();
                        }
//                        cout << endl;
                        if (choiceC != 1 && choiceC != 2 && choiceC != 3 && choiceC != 4 && choiceC != 5 &&
                            choiceC != 0 && choiceC != 6 && choiceC != 7 && choiceC != 8 && choiceC != 9)
                            throw WrongChoice();
                        switch (choiceC) {

                            case 1: {
                                ShowBooks();
                                delimitation();
                                break;
                            }
                            case 2: {
                                ShowBooksByAuthor();
                                delimitation();
                                break;
                            }
                            case 3: {
                                takeBook();
                                delimitation();
                                break;
                            }
                            case 4: {
                                returnBook();
                                delimitation();
                                break;
                            }
                            case 5: {
                                showMyBooks();
                                delimitation();
                                break;
                            }
                            case 6:{
                                changeReader();
                                delimitation();
                                break;
                            }
                            case 7: {
                                sortBookByPriceAsc();
                                delimitation();
                                break;
                            }
                            case 8: {
                                sortBooksByPriceDesc();
                                delimitation();
                                break;
                            }
                            case 9: {
                                filterBooksByPriceRange();
                                delimitation();
                                break;
                            }
                            case 0: {
                                return 0;
                            }
                            default: {
                                throw WrongChoice();
                            }

                        }

                    }
                }
                case 3:{//Instructions
                    InstructionReader instructionReader;
                    string instructions = instructionReader.readData(R"(D:\Coursework\Database\Instruction.txt)");
                    cout<<instructions<<endl;
                    delimitation();
                    break;
                }
                case 0: {
                    exit(0);
                }
                default: {
                    cout << endl;
                    throw WrongChoice();
                }

            }
        }
    }
    catch (WrongChoice &Choice) {
        cerr << Choice.what();
    }
    catch (SameID &ID) {
        cerr << ID.what();
    }
    catch (WrongInputData &Data) {
        cerr << Data.what();
    }
    catch (InvalidInput &e) {
        cerr << e.what();
    }
    catch (BookIsInFile &e) {
        cerr << e.what();
    }
    catch (InvalidInputString &e) {
        cerr << e.what();
    }
    catch (InvalidInputInt &e) {
        cerr << e.what();
    }

    return 0;
}

