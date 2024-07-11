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

void writeAuthorToFile(const Author& author, const string& filename){
    Book book1;
    Author author1;
    ofstream file(filename,ios_base::app);
    if (!file.is_open()){
        cerr<<"Error opening file: "<<endl;
        return;
    }
    file<<author1.getName()<<" "<<author1.getSurname()<<" "<<author1.getLastName()<<" "<<book1.getName()<<" "<<book1.getPrice()<<" "<<book1.getId()<<endl;
}

void writeBookToFile(const Book& book, const string& filename){
    Book book1;
    ofstream file(filename,ios_base::app);
    if (!file.is_open()){
        cerr<<"Error opening file: "<<endl;
        return;
    }
    file<<book1.getName()<<" "<<book1.getPrice()<<" "<<book1.getId()<<endl;
}

void addAuthorAndBook(){
    unique_ptr<string> name{new string {"unknown"}};
    cout<<"Enter the author`s name: ";
    cin>>*name;
    unique_ptr<string> surname{new string {"unknown"}};
    cout<<"Enter the author`s surname: ";
    cin>>*surname;
    unique_ptr<string> last_name{new string {"unknown"}};
    cout<<"Enter the author`s last name: ";
    cin>>*last_name;
    unique_ptr<string> bookName{new string {"unknown"}};
    cout<<"Enter the book`s name: ";
    cin>>*bookName;
    unique_ptr<double> bookPrice{new double {0.0}};
    cout<<"Enter the book`s price: ";
    cin>>*bookPrice;
    unique_ptr<int> bookID{new int {0}};
    cout<<"Enter the book`s ID : ";
    cin>>*bookID;

    Book newBook(*bookName,*bookPrice,*bookID);
    Author newAuthor(*name,*surname,*last_name,newBook);
    newAuthor.addBook(newBook);

    writeAuthorToFile(newAuthor,R"(D:CourseworkDatabaseAuthor+Book.txt)");
    writeBookToFile(newBook,R"(D:\Coursework\Database\Books.txt)");
}

//void addAuthorAndBook() {
//    unique_ptr<string> name{new string{"unknown"}};
//    cout << "Enter the author`s name" << endl;
//    cin >> *name;
//    unique_ptr<string> surname{new string{"unknown"}};
//    cout << "Enter the author`s surname" << endl;
//    cin >> *surname;
//    unique_ptr<string> last_name{new string{"unknown"}};
//    cout << "Enter the author`s last name" << endl;
//    cin >> *last_name;
//    unique_ptr<string> nameOfBook{new string{"unknown"}};
//    cout << "Enter the book`s name" << endl;
//    cin >> *nameOfBook;
//    unique_ptr<float> price{new float{0.0}};
//    cout << "Enter the book`s price" << endl;
//    cin >> *price;
//    unique_ptr<int> id1{new int{0}};
//    unique_ptr<int> id2{new int{0}};
//    cout << "Enter the book`s id" << endl;
//    cin >> *id1;
//    ofstream foutAuthor_Book(R"(D:\Coursework\Database\Author+Book.txt)", ios_base::app);
//    Book newBook(*nameOfBook, *price, *id1);
//    Author author(*name, *surname, *last_name, newBook);
//    foutAuthor_Book << author << endl;
//    foutAuthor_Book.close();
//
//    ofstream foutBook(R"(D:\Coursework\Database\Books.txt)", ios_base::app);
//    foutBook << newBook << endl;
//    foutBook.close();
//
//}
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
    int bookId;
    cout<<"Enter ID of the book: ";
    cin>>bookId;

    int bookstandId;
    cout<<"Enter ID of the bookstand: ";
    cin>>bookstandId;

    vector<Book> books;

    ifstream booksFile(R"(D:\Coursework\Database\Books.txt)");
    if (booksFile.is_open()){
        unique_ptr<int> id {new int {0}};
        unique_ptr<string> name {new string {"unknown"}};
        unique_ptr<float> price {new float {0.0}};
        while(booksFile>>*name>>*price>>*id){
            books.push_back({*name,*price,*id});
        }
    }
    else{
        cerr<<"Error opening file"<<endl;
        return;
    }
    booksFile.close();

    Book foundBook;
    if(findBookById(books,bookId,foundBook)){
        Bookstand bookstand(bookstandId);
        bookstand.addBook(foundBook);
        bookstand.writeBookAndBookStToFile(bookstand);
        cout<<"Book was successfully added"<<endl;
    }
    else{
        cerr<<"The book with ID "<<bookId<<"wasn`t found"<<endl;
    }
}

void ShowBooks() {
    ifstream fin(R"(D:\Coursework\Database\Author+Book.txt)");
    unique_ptr<string> name{new string{"unknown"}};
    unique_ptr<string> surname{new string{"unknown"}};
    unique_ptr<string> last_name{new string{"unknown"}};
    unique_ptr<string> nameOfBook{new string{"unknown"}};
    unique_ptr<double> price{new double{0.0}};
    unique_ptr<int> id{new int{0}};
    Book newBook(*nameOfBook, *price, *id);
    Author author(*name, *surname, *last_name, newBook);
    while (fin >> author) {
        cout << author;
    }
    fin.close();
}

void ShowReaders() {
    ifstream fin(R"(D:\Coursework\Database\Author+Book.txt)");
    unique_ptr<string> name{new string{"unknown"}};
    unique_ptr<string> surname{new string{"unknown"}};
    unique_ptr<string> last_name{new string{"unknown"}};
    unique_ptr<string> password{new string{"unknown"}};
    unique_ptr<string> nameOfBook{new string{"unknown"}};
    unique_ptr<double> price{new double{0.0}};
    unique_ptr<int> id{new int{0}};
    Book newBook(*nameOfBook, *price, *id);
    Reader reader(*name, *surname, *last_name, *password, newBook);
    while (fin >> reader) {
        cout << reader;
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
        cout<<"Here is your book: "<<endl;
        cerr << book->getName() << " " << book->getPrice() << " " << book->getId() << endl;
    } else {
        cout << "Book with this ID was not found" << endl;
    }
    return 0;
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
                        while (true) {
                            try {
                                cout << "Successful access!" << endl;
                                cout << "Choose what you want to do" << endl;
                                cout << "1. Add the book" << endl;
                                cout << "2. Add the book to the bookstand " << endl;
                                cout << "3. Show Books" << endl;
                                cout << "4. Show Readers" << endl;
                                cout << "5. Show Book by its ID" << endl;
                                cout << "0. Exit" << endl << endl;
                                int choiceAd;
                                cin >> choiceAd;
                                if (choiceAd != 1 && choiceAd != 2 && choiceAd != 3 && choiceAd != 0 && choiceAd != 4 &&
                                    choiceAd != 5)
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
                                    case 0: {
                                        return 0;

                                    }
                                    default: {
                                        throw WrongChoice();
                                    }
                                }
                                break;
                                delimitation();
                            }
                            catch (WrongChoice &Choice) {
                                cerr << Choice.what();
                            }
                            catch (SameID &ID) {
                                cerr << ID.what();
                            }
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
            case 2:// Reader
            {
                cout << "Menu of reader" << endl;
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
