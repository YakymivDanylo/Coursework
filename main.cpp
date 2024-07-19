#include <iostream>
#include <memory>
#include "fstream"
#include <vector>
#include "Reader.h"
#include "Bookstand.h"
#include "Author.h"
#include "Book.h"
#include "WrongChoice.h"
#include "WrongPassword.h"
#include "SameID.h"

using namespace std;

void delimitation() {
    cout << "-------------------------------------------------------------" << endl;
}

void clearConsole() {
    system("cls");
}

void addAuthorAndBook() {
    string name;
    cout << "Enter the author`s name: ";
    cin >> ws;
    getline(cin, name);

    string surname;
    cout << "Enter the author`s surname: ";
    cin >> ws;
    getline(cin, surname);

    string last_name;
    cout << "Enter the author`s last name: ";
    cin >> ws;
    getline(cin, last_name);
    string bookName;

    cout << "Enter the book`s name: ";
    cin >> ws;
    getline(cin, bookName);
    double bookPrice;

    cout << "Enter the book`s price: ";
    cin >> bookPrice;
    int bookID;

    cout << "Enter the book`s ID : ";
    cin >> bookID;

//    Book foundBook;
//   Book books(bookName,bookPrice,bookID);
//    if(!findBookById(books,bookID,foundBook))
//
//    Book newBook(bookName, bookPrice, bookID);
//    Author newAuthor(name, surname, last_name, newBook);

    ofstream foutAB(R"(D:\Coursework\Database\Author+Book.txt)", ios_base::app);
    foutAB << name << " " << surname << " " << last_name << " " << bookName << " " << bookPrice << " " << bookID
           << endl;
    foutAB.close();
    ofstream foutB(R"(D:\Coursework\Database\Books.txt)", ios_base::app);
    foutB << bookName << " " << bookPrice << " " << bookID << endl;
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
            fout << bookstandId << " " << name << " " << price << " " << id << endl;
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
        cerr << ch;
    }
    fin.close();
}

void ShowBookstands() {
    ifstream fin(R"(D:\Coursework\Database\Bookstands.txt)");
    string name;
    double price;
    int id;
    int idBookstand;

//    Book book(name, price, id);
//   Bookstand(idBookstand);
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
    string password;
    int id;
    Book newBook(nameOfBook, price, id);
    Reader reader(name, surname, last_name, password, newBook);
    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }
    fin.close();
}


int ShowBookById() {
    Book book1;
    int bookId;
    cout << "Enter ID of the book: ";
    cin >> bookId;
    unique_ptr<Book> book = book1.findBookById(R"(D:\\Coursework\\Database\\Books.txt)", bookId);
    if (book) {
        cout << "Here is your book: " << endl;
        cerr << book->getName() << " " << book->getPrice() << " " << book->getId() << endl;
    } else {
        cout << "Book with this ID was not found" << endl;
    }
    return 0;
}

void ShowBooksByAuthor() {

}


void registration() {
    unique_ptr<string> name{new string{"unknown"}};
    unique_ptr<string> surname{new string{"unknown"}};
    unique_ptr<string> last_name{new string{"unknown"}};
    unique_ptr<string> password{new string{"unknown"}};
    unique_ptr<string> nameOfBook{new string{"unknown"}};
    unique_ptr<float> price{new float{0.0}};
    unique_ptr<int> id{new int{0}};
    unique_ptr<int> idOfBook{new int{0}};
    cout << "Enter ID of book wich you you want to take" << endl;
    cin >> *idOfBook;
    ifstream finBook(R"(D:\Coursework\Database\Books.txt)");
    while (finBook >> *nameOfBook >> *price >> *idOfBook) {
        if (*idOfBook == *id) {
            Book newBook(*nameOfBook, *price, *id);
            ofstream foutReader(R"(D:\Coursework\Database\Reader.txt)", ios_base::app);
            cout << "Enter your full name(name,surname,last name)" << endl;
            cin >> *name >> *surname >> *last_name;
            foutReader << *name << "\t" << *surname << "\t" << *last_name << "\t" << newBook << "\t";
            cout << "Enter your password" << endl;
            Reader newReader(*name, *surname, *last_name, *password, newBook);
            foutReader.close();
        }
        finBook.close();
    }
}


int main() {
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
    delimitation();
    try {
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
                            while (true) {
                                cout << "Successful access!" << endl;
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
                                if (choiceAd != 1 && choiceAd != 2 && choiceAd != 3 && choiceAd != 0 && choiceAd != 4 &&
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
//                                break;
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
                delimitation();
                cout << "Welcome" << endl;
                cout << "You need to log in" << endl;
                cout << "Enter your name: ";
                string nameC;
                cin >> nameC;

                cout << "Enter your surname: ";
                string surnameC;
                cin >> surnameC;

                cout << "Enter your last name: ";
                string last_nameC;
                cin >> last_nameC;

                cout << "Enter your password: ";
                string password;
                cin >> password;

                while (true) {
                    cout << "Choose what you want to do " << endl;
                    cout << "1. Show Books " << endl;
                    cout << "2. Show books by author`s full name " << endl;
                    cout << "3. Take a book " << endl;
                    cout << "0. Exit " << endl<<endl;
                    int choiceC;
                    cin>> choiceC;
                    cout<<endl;
                    if(choiceC!= 1 && choiceC!= 2 && choiceC != 3)
                        throw WrongChoice();
                    switch (choiceC) {

                        case 1:{
                            ShowBooks();
                            break;
                        }
                        case 2:{
                            ShowBooksByAuthor();
                            break;
                        }
                        case 3:{
                            registration();//модифікувати функцію за умовами,які написані в блокноті
                            break;
                        }
                        case 0:{
                            return 0;
                        }
                        default: {
                            throw WrongChoice();
                        }

                    }

                }


                break;
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
    return 0;
}
