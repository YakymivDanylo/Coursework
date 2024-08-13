#include <iostream>
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
#include "WrongInputData.h"
#include "InvalidInput.h"

using namespace std;

void delimitation() {
    cout << "-------------------------------------------------------------" << endl;
}

void clearConsole() {
    system("cls");
}

void addAuthorAndBook() {

    unique_ptr<string> name{new string{"unknown"}};
    cout << "Enter the author`s name: ";
    cin >> *name;

    unique_ptr<string> surname{new string{"unknown"}};
    cout << "Enter the author`s surname: ";
    cin >> *surname;

    unique_ptr<string> last_name{new string{"unknown"}};
    cout << "Enter the author`s last name: ";
    cin >> *last_name;

    unique_ptr<string> bookName{new string{"unknown"}};
    cout << "Enter the book`s name: ";
    cin >> *bookName;

    unique_ptr<double> bookPrice{new double{0.0}};
    cout << "Enter the book`s price: ";
    cin >> *bookPrice;

//    unique_ptr<int> bookID{new int{0}};
//    cout << "Enter the book`s ID : ";
//    cin >> *bookID;
    int bookID;
    srand(time(0));
    bookID = rand();

    ifstream finB(R"(D:\Coursework\Database\Author+Book.txt)");

    unique_ptr<string> name1{new string{"unknown"}};


    unique_ptr<string> surname1{new string{"unknown"}};


    unique_ptr<string> last_name1{new string{"unknown"}};


    unique_ptr<string> bookName1{new string{"unknown"}};


    unique_ptr<double> bookPrice1{new double{0.0}};

    unique_ptr<int> bookID1{new int{0}};


    while (finB >> *name1 >> *surname1 >> *last_name1 >> *bookName1 >> *bookPrice1 >> *bookID1) {
        if (bookID == *bookID1) {
            throw SameID();
        }
        cout << name1;
    }
    finB.close();


    ofstream foutAB(R"(D:\Coursework\Database\Author+Book.txt)", ios_base::app);
    foutAB << *name << " " << *surname << " " << *last_name << " " << *bookName << " " << *bookPrice << " " << bookID
           << endl;
    foutAB.close();
    ofstream foutB(R"(D:\Coursework\Database\Books.txt)", ios_base::app);
    foutB << *bookName << " " << *bookPrice << " " << bookID << endl;
    foutB.close();

}

bool findBookById(const vector<Book> &books, int id, Book &foundBook) {
    for (const Book &book: books) {
        if (book.getId() == id) {
            foundBook = book;
            return true;
        }
    }
    return false;
}


void addBookstand() {
    string name;
    double price;
    int id;

    int bookId;
    cout << "Enter ID of the book: ";
    cin >> bookId;

    int bookstandId;
    cout << "Enter ID of the bookstand: ";
    cin >> bookstandId;

    vector<Book> books;

    ifstream booksFile(R"(D:\Coursework\Database\Books.txt)");
    if (booksFile.is_open()) {
        while (booksFile >> name >> price >> id)
            books.push_back({name, price, id});
    } else {
        cerr << "Error opening file" << endl;
        return;
    }
    booksFile.close();


    Book foundBook(name, price, id);
    if (findBookById(books, bookId, foundBook)) {
        Bookstand bookstand(bookstandId);
        bookstand.addBook(foundBook);
        ofstream fout(R"(D:\Coursework\Database\Bookstands.txt)", ios_base::app);
        if (fout.is_open()) {
            fout << bookstandId << " " << foundBook << endl;
            cout << "Book was successfully added" << endl;
            fout.close();
        } else {
            cerr << "Error opening file" << endl;
        }

    } else {
        cerr << "The book with ID " << bookId << " wasn`t found" << endl;
    }
}

void ShowBooks() {
    ifstream fin(R"(D:\Coursework\Database\Author+Book.txt)");
    string name, surname, last_name, nameOfBook;
    double price;
    int id;
    Book book(nameOfBook, price, id);
    Author author(name, surname, last_name, book);
    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }
    fin.close();
}

void ShowBookstands() {
    ifstream fin(R"(D:\Coursework\Database\Bookstands.txt)");
    string name;
    double price;
    int id;
    int idBookstand;

    char ch;
    while (fin.get(ch)) {
        cerr << ch;
    }
    fin.close();
}

void ShowReaders() {
    ifstream fin(R"(D:\Coursework\Database\Reader.txt)");
    string name, surname, last_name, nameOfBook;
    double price;
    int id;
    Book newBook(nameOfBook, price, id);
    Reader reader(name, surname, last_name, newBook);
    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }
    fin.close();
}


int ShowBookById() {
    Book book1;
    Reader reader;
    Author author;
    int bookId;
    cout << "Enter ID of the book: ";
    cin >> bookId;
    unique_ptr<Book> book = book1.findBookById(R"(D:\Coursework\Database\Books.txt)", bookId);
    if (book) {
        cout << "Here is your book: " << endl;
        cerr << book->getName() << " " << book->getPrice() << " " << book->getId() << endl;
    } else {
        cout << "Book with this ID was not found" << endl;
        string name, surname, last_name, nameOfBook;
        string name2, surname2, last_name2;
        string nameAu, surnameAu, last_nameAu;
        float price;
        int id;
        ifstream finR(R"(D:\Coursework\Database\Reader.txt)");
        while (finR >> name2 >> surname2 >> last_name2 >> nameAu >> surnameAu >> last_nameAu >> nameOfBook >> price
                    >> id) {
            if (bookId == id) {
                Book book2(nameOfBook, price, bookId);
                Author author2(nameAu, surnameAu, last_nameAu, book2);
                cout << name2 << " " << surname2 << " " << last_name2 << " " << author2;
                cout << "This book is taken" << endl;
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
    cout << "Enter author`s surname: ";
    cin >> *surname;
    cout << "Enter author`s last name: ";
    cin >> *last_name;
    ifstream finAB(R"(D:\Coursework\Database\Author+Book.txt)");
    Book book;
    Author author;
    int counter = 0;
    while (finAB >> author) {
        if (*name == author.getName() && *surname == author.getSurname() && *last_name == author.getLastName()) {
            book = author.getBook();
            cerr << book;
        }
//        else {
//            if (*name != author.getName() || *surname != author.getSurname() || *last_name != author.getLastName()) {
//                counter++;
//                if (counter != 0) {
//
//                    cerr << "There is no reader with this name!" << endl;
//                    cerr << "Check if you entered the name correctly!" << endl;
//                }
//            }
//        }
    }
    finAB.close();
}

void showMyBooks() {
    cout << "You need to log in" << endl;
    string name, surname, last_name, nameOfBook;
    string name2, surname2, last_name2;
    string nameAu, surnameAu, last_nameAu;
    float price;
    int id;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your surname: ";
    cin >> surname;
    cout << "Enter your last name: ";
    cin >> last_name;

    ifstream finR(R"(D:\Coursework\Database\Reader.txt)");
    Book book;
    Author author;
    Reader reader;
    int counter = 0;
    while (finR >> name2 >> surname2 >> last_name2 >> nameAu >> surnameAu >> last_nameAu >> nameOfBook >> price >> id) {
        if (name == name2 && surname == surname2 && last_name == last_name2) {
            Book newBook(nameOfBook, price, id);
            Author newAuthor(nameAu, surnameAu, last_nameAu, newBook);
            cerr << newAuthor << endl;
        }
        if (name != name2 || surname != surname2 || last_name != last_name2) {
            counter++;
            if (counter > 0)
                cerr << "There is no reader with this name!" << endl;
            cerr << "Check if you entered the name correctly!" << endl;
        }
    }
    finR.close();

}


void takeBook() {
    cout << "You need to log in" << endl;
    string name, surname, last_name, nameOfBook;
    string nameAu, surnameAu, last_nameAu;
    float price;
    int id, idOfBook, idBs;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your surname: ";
    cin >> surname;
    cout << "Enter your last name: ";
    cin >> last_name;
    cout << "Enter book`s ID which you want to take: ";
    cin >> idOfBook;
    ifstream finBook(R"(D:\Coursework\Database\Books.txt)");
    ofstream foutBookTemp(R"(D:\Coursework\Database\Books_temp.txt)", ios_base::app);

    ifstream finBookstand(R"(D:\Coursework\Database\Bookstands.txt)");
    ofstream foutBookstandTemp(R"(D:\Coursework\Database\Bookstands_temp.txt)", ios_base::app);

    ifstream finAuthorBook(R"(D:\Coursework\Database\Author+Book.txt)");
    ofstream foutAuthorBookTemp(R"(D:\Coursework\Database\Author+Book_temp.txt)", ios_base::app);
    bool bookFound = false;

    while (finAuthorBook >> nameAu >> surnameAu >> last_nameAu >> nameOfBook >> price >> id) {
        if (idOfBook == id) {
            bookFound = true;
            string line;
            while (getline(finAuthorBook, line)) {
                if (idOfBook != id) {
                    foutAuthorBookTemp << line << std::endl;
                }
            }

            while (getline(finBook, line)) {
                if (idOfBook != id) {
                    foutBookTemp << line << endl;
                }
            }


            Book newBook(nameOfBook, price, idOfBook);
            Author author(nameAu, surnameAu, last_nameAu, newBook);
            Reader newReader(name, surname, last_name, newBook);

            ofstream foutReader(R"(D:\Coursework\Database\Reader.txt)", ios_base::app);
            foutReader << name << " " << surname << " " << last_name << " " << nameAu << " "
                       << surnameAu << " " << last_nameAu << " " << nameOfBook << " " << price << " " << idOfBook
                       << endl;
            foutReader.close();
        } else {
            foutAuthorBookTemp << nameAu << " " << surnameAu << " " << last_nameAu << " " << nameOfBook << " " << price
                               << " " << id << endl;
            foutBookTemp << nameOfBook << " " << price << " " << id << endl;
        }
    }

    while (finBookstand >> idBs >> nameOfBook >> price >> id) {
        if (idOfBook == id) {
            bookFound = true;
            string line;
            while (getline(finBookstand, line)) {
                if (idOfBook != id) {
                    foutBookstandTemp << line << endl;
                }
                Bookstand bookstand(idBs);
            }
        } else {
            foutBookstandTemp << idBs << " " << nameOfBook << " " << price << " " << id << endl;
        }
    }

    if (!bookFound) {
        cerr << "Book with this ID was not found" << endl;
    }

    finBook.close();
    foutBookTemp.close();
    finBookstand.close();
    foutBookstandTemp.close();
    finAuthorBook.close();
    foutAuthorBookTemp.close();

    remove(R"(D:\Coursework\Database\Books.txt)");
    rename(R"(D:\Coursework\Database\Books_temp.txt)", R"(D:\Coursework\Database\Books.txt)");

    remove(R"(D:\Coursework\Database\Author+Book.txt)");
    rename(R"(D:\Coursework\Database\Author+Book_temp.txt)", R"(D:\Coursework\Database\Author+Book.txt)");

    remove(R"(D:\Coursework\Database\Bookstands.txt)");
    rename(R"(D:\Coursework\Database\Bookstands_temp.txt)", R"(D:\Coursework\Database\Bookstands.txt)");

}

void returnBook() {
    cout << "You need to log in" << endl;
    string name, surname, last_name, nameOfBook;
    string name2, surname2, last_name2;
    string nameAu, surnameAu, last_nameAu;
    float price;
    int id, idOfBook;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your surname: ";
    cin >> surname;
    cout << "Enter your last name: ";
    cin >> last_name;
    cout << "Enter book`s ID which you want to return: ";
    cin >> idOfBook;


    ofstream foutBook(R"(D:\Coursework\Database\Books.txt)", ios_base::app);

    ifstream finReader(R"(D:\Coursework\Database\Reader.txt)");
    ofstream foutReaderTemp(R"(D:\Coursework\Database\Reader_temp.txt)", ios_base::app);

    ofstream foutAuthorBook(R"(D:\Coursework\Database\Author+Book.txt)", ios_base::app);

    bool bookFound = false;
    int counter = 0;
    while (finReader >> name2 >> surname2 >> last_name2 >> nameAu >> surnameAu >> last_nameAu >> nameOfBook >> price
                     >> id) {
        if (name != name2 || surname != surname2 || last_name != last_name2) {
            counter++;
            if (counter >= 1) {
                cerr << "There is no reader with this name!" << endl;
                break;
            }
        } else {
            if (idOfBook == id) {
                bookFound = true;
                string line;
                while (getline(finReader, line)) {
                    if (idOfBook != id) {
                        foutReaderTemp << line << endl;
                    }
                }
                foutBook << nameOfBook << " " << price << " " << idOfBook << endl;


                foutAuthorBook << nameAu << " " << surnameAu << " " << last_nameAu << " " << nameOfBook << " " << price
                               << " " << idOfBook << endl;

            } else {
                foutReaderTemp << name2 << " " << surname2 << " " << last_name2 << " " << nameAu << " " << surnameAu
                               << " "
                               << last_nameAu << " " << nameOfBook << " " << price << " " << id << endl;
            }
        }
    }
    if (!bookFound) {
        cerr << "Book with this ID was not found" << endl;
    }

    foutBook.close();
    foutAuthorBook.close();
    foutReaderTemp.close();
    finReader.close();

    remove(R"(D:\Coursework\Database\Reader.txt)");
    rename(R"(D:\Coursework\Database\Reader_temp.txt)", R"(D:\Coursework\Database\Reader.txt)");
}


int main() {
    try {
        delimitation();
        cout << "Welcome to our library" << endl;
        cout << "Choose what you want to do: " << endl;
        cout << "1. Administrator" << endl;
        cout << "2. Reader" << endl;
        cout << "3. Instructions" << endl;
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
                    cout << "Enter password" << endl;
                    cin >> password;
                    delimitation();
                    if (password == "123") {
                        try {
                            cout << "Successful access!" << endl;
                            while (true) {
                                cout << "Choose what you want to do" << endl;
                                cout << "1. Add the book" << endl;
                                cout << "2. Add the book to the bookstand " << endl;
                                cout << "3. Show Books" << endl;
                                cout << "4. Show Readers" << endl;
                                cout << "5. Show Book by its ID" << endl;
                                cout << "6. Show bookstands" << endl;
                                cout << "7. Show books by author`s full name " << endl;
                                cout << "0. Exit" << endl << endl;
                                int choiceAd;
                                cin >> choiceAd;
                                if (cin.fail()) {
                                    throw InvalidInput();
                                }
                                if (choiceAd != 1 && choiceAd != 2 && choiceAd != 3 && choiceAd != 0 &&
                                    choiceAd != 4 &&
                                    choiceAd != 5 && choiceAd != 6 && choiceAd != 7)
                                    throw WrongChoice();
                                switch (choiceAd) {
                                    case 1: {
                                        addAuthorAndBook();
                                        break;
                                    }
                                    case 2: {
                                        addBookstand();
                                        break;
                                    }
                                    case 3: {
                                        ShowBooks();
                                        break;
                                    }
                                    case 4: {
                                        ShowReaders();
                                        break;
                                    }
                                    case 5: {
                                        ShowBookById();
                                        break;

                                    }
                                    case 6: {
                                        ShowBookstands();
                                        break;

                                    }
                                    case 7: {
                                        ShowBooksByAuthor();
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
                        catch (WrongChoice &Choice) {
                            cerr << Choice.what();
                        }
                        catch (SameID &ID) {
                            cerr << ID.what();
                        }

                    } else {
                        cerr << "Wrong password" << endl;
                        k++;
                    }
                }
                if (k == 3) {
                    cerr << "You have reached the maximum number of attempts. The program ends." << endl;
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
                    cout << "0. Exit " << endl << endl;
                    int choiceC;
                    cin >> choiceC;
                    if (cin.fail()) {
                        throw InvalidInput();
                    }
                    cout << endl;
                    if (choiceC != 1 && choiceC != 2 && choiceC != 3 && choiceC != 4 && choiceC != 5 &&
                        choiceC != 0)
                        throw WrongChoice();
                    switch (choiceC) {

                        case 1: {
                            ShowBooks();
                            break;
                        }
                        case 2: {
                            ShowBooksByAuthor();
                            break;
                        }
                        case 3: {
                            takeBook();//модифікувати функцію за умовами,які написані в блокноті
                            break;
                        }
                        case 4: {
                            returnBook();
                            break;
                        }
                        case 5: {
                            showMyBooks();
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
            case 3://Instructions
            {
                cout << "Instructions" << endl;
                break;
            }
            case 0: {
                exit(0);
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
    return 0;
}
