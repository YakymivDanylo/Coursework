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

void addReader() {
    unique_ptr<Reader> newReader{new Reader()};
    cin >> *newReader;
    ofstream fout(R"(D:\Coursework\Database\Reader.txt)", ios_base::app);
    fout << *newReader << endl;
    fout.close();
}

bool isID_B_inFile(int ID_BookToPut){
    ifstream finID(R"(D:\Coursework\Database\Books.txt)");
    if(!finID.is_open()){
        throw ErrorOpening();
    }
    else
    {
        unique_ptr<string> nameOfBook{new string{"unknown"}};
        unique_ptr<float> price{new float{0.0}};
        unique_ptr<int> id{new int{0}};
        while (finID>>*nameOfBook>>*price>>*id){
            if(ID_BookToPut!=*id){
                finID.close();
                return true;
            }
        }
        finID.close();
        return false;
    }
}


void addAuthorAndBook(Book book) {
    unique_ptr<string> name{new string{"unknown"}};
    cout << "Enter the author`s name" << endl;
    cin >> *name;
    unique_ptr<string> surname{new string{"unknown"}};
    cout << "Enter the author`s surname" << endl;
    cin >> *surname;
    unique_ptr<string> last_name{new string{"unknown"}};
    cout << "Enter the author`s last name" << endl;
    cin >> *last_name;
    unique_ptr<string> nameOfBook{new string{"unknown"}};
    cout << "Enter the book`s name" << endl;
    cin >> *nameOfBook;
    unique_ptr<float> price{new float{0.0}};
    cout << "Enter the book`s price" << endl;
    cin >> *price;
    unique_ptr<int> id1{new int{0}};
    unique_ptr<int> id2{new int{0}};
    cout << "Enter the book`s id" << endl;
    cin >> *id1;
    if(!isID_B_inFile(book.getId())){
        ofstream foutAuthor_Book(R"(D:\Coursework\Database\Author+Book.txt)", ios_base::app);
        Book newBook(*nameOfBook, *price, *id1);
        Author author(*name, *surname, *last_name, newBook);
        foutAuthor_Book << author << endl;
        foutAuthor_Book.close();

        ofstream foutBook(R"(D:\Coursework\Database\Books.txt)", ios_base::app);
        foutBook << newBook << endl;
        foutBook.close();
    }
}

//bool isBookstandInFile(int ID) {
//    ifstream finBkStd(R"("D:\Coursework\Database\Bookstands.txt")");
//    try {
//        if (!finBkStd.is_open())
//            throw ErrorOpening();
//        else {
//            unique_ptr<int> idBookstand{new int{0}};
//            unique_ptr<string> name{new string{"unknown"}};
//            unique_ptr<string> surname{new string{"unknown"}};
//            unique_ptr<string> last_name{new string{"unknown"}};
//            unique_ptr<double> price{new double{0.0}};
//            unique_ptr<int> id2{new int{0}};
//            while (finBkStd >> *idBookstand >> *name >> *surname >> *last_name >> *id2) {
//                if (ID == *idBookstand) {
//                    return true;
//                }
//            }
//            finBkStd.close();
//            return false;
//        }
//    }
//    catch (ErrorOpening &Error) {
//        cerr << Error.what();
//    }
//}

void addBookstand() {
    unique_ptr<int> idBookstand{new int{0}};
    cout << "Enter ID of Bookstand " << endl;
    cin >> *idBookstand;
    unique_ptr<string> name{new string{"unknown"}};
    unique_ptr<string> surname{new string{"unknown"}};
    unique_ptr<string> last_name{new string{"unknown"}};
    unique_ptr<string> nameOfBook{new string{"unknown"}};
    unique_ptr<float> price{new float{0.0}};
    unique_ptr<int> id1{new int{0}};
    unique_ptr<int> id2{new int{0}};
    ifstream finBook(R"(D:\Coursework\Database\Author+Book.txt)");
    cout << "Enter the ID of the book you want to place on the bookstand" << endl;
    cin >> *id2;
    while (finBook >> *name >> *surname >> *last_name >> *nameOfBook >> *price >> *id1) {
        if (*id2 == *id1) {
            ofstream fout(R"(D:\Coursework\Database\Bookstands.txt)", ios_base::app);
            Book newBook(*nameOfBook, *price, *id1);
            Author author(*name, *surname, *last_name, newBook);
            Bookstand bookstand(*idBookstand, newBook);
            fout << bookstand << endl;
            fout.close();
        }
    }
    finBook.close();
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
                            cout << "Successful access!" << endl;
                            cout << "Choose what you want to do" << endl;
                            cout << "1. Add the book" << endl;
                            cout << "2. Add the book to the bookstand " << endl;
                            cout << "3. Action 3" << endl;
                            cout << "0. Exit" << endl << endl;
                            int choiceAd;
                            cin >> choiceAd;
                            if (choiceAd != 1 && choiceAd != 2 && choiceAd != 3 && choiceAd != 0)
                                throw WrongChoice();
                            switch (choiceAd) {
                                case 1: {
                                    addAuthorAndBook(newBook);
                                    break;
                                }
                                case 2: {
                                    addBookstand();
                                    break;
                                }
                                case 3: {
                                    //зчитати книги
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
