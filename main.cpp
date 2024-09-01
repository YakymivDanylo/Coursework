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
#include "chrono"

using namespace std;

void delimitation() {
    cout << "-------------------------------------------------------------" << endl;
}

void delimitation2() {
    cout << "===============================================================" << endl;
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
        Book book(*bookName, *bookPrice, bookID);
        Author author(*name, *surname, *last_name, book);
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


void addBookstand() {

    unique_ptr<string> name {new string {"unknwon"}};
    unique_ptr<double> price {new double {0}};
    unique_ptr<int> id {new int {0}};
    unique_ptr<int> bookId {new int {0}};
    int bookstandId;

    srand(time(0));
    bookstandId = rand();

    cout << "Enter ID of the book: ";
    cin >> *bookId;

    int counter = 0;
    ifstream booksFile(R"(D:\Coursework\Database\Books.txt)");
    ofstream foutbookstand(R"(D:\Coursework\Database\Bookstands.txt)", ios_base::app);

    if (booksFile.is_open()) {
        while (booksFile >> *name>>*price>>*id) {
            if (*bookId == *id) {
                Book book1(*name, *price, *bookId);
                Bookstand bookstand(bookstandId, book1);
                    foutbookstand<<bookstand<<endl;
                counter++;
            }
        }
        booksFile.close();
        if (counter == 0) {
            cerr << "There is no book with this ID or this book is already in the bookstand!" << endl;
        }

    } else {
        cerr << "Error opening file" << endl;
        return;
    }

}

void ShowBooks() {
    ifstream fin(R"(D:\Coursework\Database\Author+Book.txt)");
    unique_ptr<string> name{new string{"unknown"}};
    unique_ptr<string> nameOfBook{new string{"unknown"}};
    unique_ptr<string> surname{new string{"unknown"}};
    unique_ptr<string> last_name{new string{"unknown"}};
    unique_ptr<double> price{new double{0}};
    unique_ptr<int> id{new int{0}};
    Book book(*nameOfBook, *price, *id);
    Author author(*name, *surname, *last_name, book);
    int counter = 1;
    delimitation2();
//    while (fin >> *name >> *surname >> *last_name >> *nameOfBook >> *price >> *id) {
//        cout << "Book number: " << counter++ << endl;
//        cout << endl;
//        cout << "Author`s name:" << "\t" << *name << endl;
//        cout << "Author`s surname:" << "\t" << *surname << endl;
//        cout << "Author`s last name:" << "\t" << *last_name << endl;
//        cout << endl;
//        cout << "Book`s name:" << "\t" << *nameOfBook << endl;
//        cout << "Book`s price:" << "\t" << *price << endl;
//        cout << "Book`s id:" << "\t" << *id << endl;
//        cout << endl;
//        delimitation2();
//    }
    while (fin >> author) {
        cout << "Book number: " << counter++ << endl;
        cout << endl;
        cout << "Author`s name:" << "\t" << author.getName() << endl;
        cout << "Author`s surname:" << "\t" << author.getSurname() << endl;
        cout << "Author`s last name:" << "\t" << author.getLastName() << endl;
        cout << endl;
        cout << "Book`s name:" << "\t" << author.getNameBook() << endl;
        cout << "Book`s price:" << "\t" << author.getPriceBook()<< endl;
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
    Book book(*name,*price,*id);
    Bookstand bookstand(*idBookstand,book);
    delimitation2();
//    while (fin >> *idBookstand >> *name >> *price >> *id) {
//        cout << "Bookstand with ID:" << "\t" << *idBookstand << endl;
//        cout << "Book`s name:" << "\t" << *name << endl;
//        cout << "Book`s price:" << "\t" << *price << endl;
//        cout << "Book`s ID:" << "\t" << *id << endl;
//        delimitation2();
//    }
    while (fin >> bookstand) {
        cout << "Bookstand with ID:" << "\t" << bookstand.getIdBookstand() << endl;
        cout << "Book`s name:" << "\t" << bookstand.getNameBook() << endl;
        cout << "Book`s price:" << "\t" << bookstand.getPriceBook() << endl;
        cout << "Book`s ID:" << "\t" << bookstand.getIdBook()<< endl;
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

    Book book(*nameOfBook,*price,*idBook);
    Author author(*nameAuthor,*surnameAuthor,*last_nameAuthor,book);
    Reader reader(*nameReader,*surnameReader,*last_nameReader,*idReader);
    delimitation2();
    while (fin >> reader>>author) {
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
    cin >> bookId;
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

        Reader reader1(*name,*surname,*last_name,*idR);

        unique_ptr<string> nameOfBook{new string{"unknown"}};
        unique_ptr<double> price{new double{0}};
        unique_ptr<int> id{new int{0}};

        Book book3(*nameOfBook,*price,*id);

        unique_ptr<string> nameAu{new string{"unknown"}};
        unique_ptr<string> surnameAu{new string{"unknown"}};
        unique_ptr<string> last_nameAu{new string{"unknown"}};

        Author author1(*nameAu,*surnameAu,*last_nameAu,book3);

        ifstream finR(R"(D:\Coursework\Database\Reader.txt)");

        while (finR >> reader1>>author1) {
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
                cout << "Author`s name:" << "\t" << author2.getName() << endl;
                cout << "Author`s surname:" << "\t" << author2.getSurname() << endl;
                cout << "Author`s last name:" << "\t" << author2.getLastName() << endl;
                cout << endl;
                cout << "Book`s name:" << "\t" << author2.getNameBook() << endl;
                cout << "Book`s price:" << "\t" << author2.getPriceBook() << endl;
                cout << "Book`s ID:" << "\t" << author2.getId() << endl;
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
    cout << "Enter author`s surname: ";
    cin >> *surname;
    cout << "Enter author`s last name: ";
    cin >> *last_name;
    ifstream finAB(R"(D:\Coursework\Database\Author+Book.txt)");
    Book book;
    Author author;
    int counter = 0;
    delimitation();
    while (finAB >> author) {
        if (*name == author.getName() && *surname == author.getSurname() && *last_name == author.getLastName()) {
            book = author.getBook();
            cout << book;
            counter++;
        }
    }
    finAB.close();
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
    cout << "Enter your surname: ";
    cin >> *surname;
    cout << "Enter your last name: ";
    cin >> *last_name;
    cout << "Enter your ID: ";
    cin >> *idR;
    cout << endl;
    ifstream finR(R"(D:\Coursework\Database\Reader.txt)");
    Book book;
    Author author;
    Reader reader;
    int counter = 0;
    int counterBook = 1;

    Reader enterReader(*name,*surname,*last_name,*idR);
    Reader readReader(*name2,*surname2,*last_name2,*idR2);
    Book book1(*nameOfBook,*price,*id);
    Author author1(*nameAu,*surnameAu,*last_nameAu,book);


//    while (finR >> *name2 >> *surname2 >> *last_name2 >> *idR2 >> *nameAu >> *surnameAu >> *last_nameAu >> *nameOfBook
//                >> *price
//                >> *id) {
//        delimitation2();
//        if (*name == *name2 && *surname == *surname2 && *last_name == *last_name2 && *idR == *idR2) {
//            Book newBook(*nameOfBook, *price, *id);
//            Author newAuthor(*nameAu, *surnameAu, *last_nameAu, newBook);
//
//            cout << "Book number:" << "\t" << counterBook++ << endl;
//            cout << endl;
//            cout << "Author`s name:" << "\t" << *nameAu << endl;
//            cout << "Author`s surname:" << "\t" << *surnameAu << endl;
//            cout << "Author`s last name:" << "\t" << *last_nameAu << endl;
//            cout << endl;
//            cout << "Book`s name:" << "\t" << *nameOfBook << endl;
//            cout << "Book`s price:" << "\t" << *price << endl;
//            cout << "Book`s ID:" << "\t" << *id << endl;
//            delimitation2();
//            counter++;
//        }
//    }

    while (finR >> readReader>>author1) {
        delimitation2();
//        if (*name == *name2 && *surname == *surname2 && *last_name == *last_name2 && *idR == *idR2)
            if (enterReader.getName() == readReader.getName() && enterReader.getSurname() == readReader.getSurname() && enterReader.getLastName() == readReader.getLastName() && enterReader.getID() == readReader.getID()){
//            Book newBook(*nameOfBook, *price, *id);
//            Author newAuthor(*nameAu, *surnameAu, *last_nameAu, newBook);

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
    cout << "Enter your surname: ";
    cin >> *surname;
    cout << "Enter your last name: ";
    cin >> *last_name;
    cout << "Create your own ID and remember it!\n If you have one enter it.\n";
    cout << "Enter your ID:";
    cin >> *idR;
    cout << "Enter book`s ID which you want to take: ";
    cin >> *idOfBook;

    Reader reader1(*name,*surname,*last_name,*idR);

    ifstream finAuthor(filenameAuthor);
    while (finAuthor >> *nameAu >> *surnameAu >> *last_nameAu >> *nameOfBook >> *price >> *id) {
        if (*idOfBook == *id) {

            Book book(*nameOfBook,*price,*idOfBook);
            Author author(*nameAu,*surnameAu,*last_nameAu,book);
            Reader reader(*name,*surname,*last_name,*idR);

            ofstream foutReader(filenameReader, ios_base::app);
//            foutReader << *name << " " << *surname << " " << *last_name << " " << *idR << " " << *nameAu << " "
//                       << *surnameAu << " " << *last_nameAu << " " << *nameOfBook << " " << *price << " " << *idOfBook
//                       << endl;
                foutReader<<reader.getName()<<" "<<reader.getSurname()<<" "<<reader.getLastName()<<" "<<reader.getID()<<" "<<author.getName()<<" "<<author.getSurname()<<" "<<author.getLastName()<<" "<<author.getNameBook()<<" "<<author.getPriceBook()<<" "<<author.getId()<<endl;
            foutReader.close();
        }

    }

    finAuthor.close();

    ifstream finAuthor1(filenameAuthor);
    ofstream foutAuthor("tempAuthor.txt");
    while (finAuthor1 >> *nameAu >> *surnameAu >> *last_nameAu >> *nameOfBook >> *price >> *id) {
        if (*idOfBook != *id) {

            Book book(*nameOfBook,*price,*id);
            Author author(*nameAu,*surnameAu,*last_nameAu,book);
//            foutAuthor << *nameAu << " " << *surnameAu << " " << *last_nameAu << " " << *nameOfBook << " " << *price
//                       << " " << *id << endl;
            foutAuthor<<author.getName()<<" "<<author.getSurname()<<" "<<author.getLastName()<<" "<<author.getNameBook()<<" "<<author.getPriceBook()<<" "<<author.getId()<<endl;
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
            Book book(*nameOfBook,*price,*id);
//            foutBook << *nameOfBook << " " << *price << " " << *id << endl;
            foutBook << book.getName()<<" "<<book.getPrice()<<" "<<book.getId()<< endl;
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
            Book book(*nameOfBook,*price,*id);
            Bookstand bookstand(*idBs,book);
//            foutBookstand << *idBs << *nameOfBook << " " << *price << " " << *id << endl;
            foutBookstand << bookstand.getIdBookstand()<<" "<<bookstand.getNameBook()<<" "<<bookstand.getPriceBook()<<" "<<bookstand.getIdBook()<< endl;
        }
    }
    foutBookstand.close();
    finBookstand.close();

    remove(filenameBookstand.c_str());
    rename("tempBookstand.txt", filenameBookstand.c_str());


//    cout << "Book with ID " << *idOfBook << " was taken by " << *name << " " << *surname << " " << *last_name << " "
//         << *idR << endl;
    cout << "Book with ID\t" << *idOfBook << "\twas taken by\t" << reader1.getName() << "\t" << reader1.getSurname() << "\t" << reader1.getLastName() << "\t"
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
    cout << "Enter your surname: ";
    cin >> *surname;
    cout << "Enter your last name: ";
    cin >> *last_name;
    cout << "Enter your ID: ";
    cin >> *idR;
    cout << "Enter book`s ID which you want to return: ";
    cin >> *idOfBook;

    Reader reader1(*name,*surname,*last_name,*idR);


    ifstream finReader(filenameReader);
    while (finReader >> *name >> *surname >> *last_name >> *idR2 >> *nameAu >> *surnameAu >> *last_nameAu >> *nameOfBook >> *price >> *id) {
        if (*idOfBook == *id && *idR==*idR2 ) {

            Book book(*nameOfBook,*price,*idOfBook);

            ofstream foutBook(filenameBook, ios_base::app);
//            foutBook << *nameOfBook << " " << *price << " " << *idOfBook << endl;
            foutBook << book.getName() << " " << book.getPrice() << " " << book.getId() << endl;
            foutBook.close();

            Author author(*nameAu,*surnameAu,*last_nameAu,book);
            ofstream foutAuthor(filenameAuthor, ios_base::app);
//            foutAuthor << *nameAu << " " << *surnameAu << " " << *last_nameAu << " " << *nameOfBook << " " << *price
//                       << " " << *idOfBook << endl;
            foutAuthor << author.getName() << " " << author.getSurname() << " " << author.getLastName() << " " << author.getNameBook() << " " << author.getPriceBook()
                       << " " << author.getId() << endl;
            foutAuthor.close();
        }
    }
    finReader.close();


    ifstream finReader1(filenameReader);
    ofstream foutReader("tempReader.txt");
    while (finReader1 >> *name >> *surname >> *last_name >> *idR2 >> *nameAu >> *surnameAu >> *last_nameAu >> *nameOfBook >> *price >> *id) {
        if (*idOfBook != *id) {
            Reader reader(*name,*surname,*last_name,*idR2);
            Book book(*nameOfBook,*price,*id);
            Author author(*nameAu,*surnameAu,*last_nameAu,book);

//            foutReader << *name << " " << *surname << " " << *last_name << " " << *idR2 << " " << *nameAu << " "
//                       << *surnameAu << " " << *last_nameAu << " " << *nameOfBook << " " << *price << " " << *id
//                       << endl;
            foutReader << reader.getName() << " " << reader.getSurname() << " " << reader.getLastName() << " " << reader.getID() << " " << author.getName() << " "
                       << author.getSurname() << " " << author.getLastName() << " " << author.getNameBook() << " " << author.getPriceBook() << " " << author.getId()
                       << endl;
        }
    }
    foutReader.close();
    finReader1.close();

    remove(filenameReader.c_str());
    rename("tempReader.txt", filenameReader.c_str());

    cout << "Book with ID " << *idOfBook << endl;
    cout << " was successfully returned" << endl;


}


int main() {
//    system("chcp 65001");

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
                    cout << endl;
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
                                cout << "3. Show books" << endl;
                                cout << "4. Show readers" << endl;
                                cout << "5. Show book by its ID" << endl;
                                cout << "6. Show bookstands" << endl;
                                cout << "7. Show books by author`s full name " << endl;
                                cout << "0. Exit" << endl << endl;
                                int choiceAd;
                                cin >> choiceAd;
                                delimitation();
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
                        case 0: {
                            return 0;
                            delimitation();
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
                delimitation();
                break;
            }
            case 0: {
                exit(0);
                delimitation();
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
