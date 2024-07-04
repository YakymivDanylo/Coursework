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
using namespace std;

void delimitation(){
    cout<<"-------------------------------------------------------------"<<endl;
}
void clearConsole(){
    system("cls");
}

vector<Reader> readersFromFile(){
    shared_ptr<Reader> reader;
    vector <Reader> readers;
    ifstream fin(R"(D:\Coursework\Database\Reader.txt)");
    while (fin >> *reader)
        readers.push_back(*reader);
    fin.close();
    return readers;
}

vector<Author> authorFromFile(){
    shared_ptr<Author> author;
    vector<Author> authors;
    ifstream fin(R"(D:\Coursework\Database\Author+Book.txt)");
    while(fin>>*author){
        authors.push_back(*author);
    }
    fin.close();
    return authors;
}

vector<Book> bookFromFile(){
    shared_ptr<Book> book;
    vector<Book> books;
    ifstream fin(R"(D:\Coursework\Database\Books.txt)");
    while (fin>>*book){
        books.push_back(*book);
    }
    fin.close();
    return books;
}

void addBook(){
    unique_ptr  <Book> newBook  {new Book()};
    cin>>*newBook;
    ofstream fout(R"(D:\Coursework\Database\Books.txt)",ios_base::app);
    fout<<*newBook<<endl;
    fout.close();
}

void addReader(){
    unique_ptr <Reader> newReader {new Reader()};
    cin>>*newReader;
    ofstream fout(R"(D:\Coursework\Database\Reader.txt)",ios_base::app);
    fout<<*newReader<<endl;
    fout.close();
}

void addAuthorAndBook() {
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
        unique_ptr<int> id{new int{0}};

        ofstream foutAuthor_Book(R"(D:\Coursework\Database\Author+Book.txt)", ios_base::app);
        Book book1(*nameOfBook,*price,*id);
        foutAuthor_Book << *name << "\t" << *surname << "\t" << *last_name << "\t" << *nameOfBook << "\t" << *price
                        << "\t" << *id << endl;
        foutAuthor_Book.close();

        ofstream foutBook(R"(D:\Coursework\Database\Books.txt)", ios_base::app);
        foutBook<<book1;
//        foutBook << *nameOfBook << "\t" << *price << "\t" << *id << endl;
        foutBook.close();

}

void addBookstand() {
    unique_ptr<Bookstand> newBookstand {new Bookstand()};
    cin>>*newBookstand;
    ofstream fout(R"(D:\Coursework\Database\Bookstands.txt)",ios_base::app);
    fout<<*newBookstand<<endl;
    fout.close();
}

void registration(){
    unique_ptr<string> name{new string {"unknown"}};
    unique_ptr<string> surname{new string {"unknown"}};
    unique_ptr<string> last_name{new string {"unknown"}};
    unique_ptr<string> password{new string {"unknown"}};
    unique_ptr<string> nameOfBook{new string {"unknown"}};
    unique_ptr<float> price{new float {0.0}};
    unique_ptr<int> id {new int {0}};
    unique_ptr<int> idOfBook {new int {0}};
    cout<<"Enter ID of book wich you you want to take"<<endl;
    cin>>*idOfBook;
    ifstream finBook(R"(D:\Coursework\Database\Books.txt)");
    while(finBook>>*nameOfBook>>*price>>*idOfBook){
        if(*idOfBook==*id){
            Book newBook(*nameOfBook,*price,*id);
            ofstream foutReader(R"(D:\Coursework\Database\Reader.txt)",ios_base::app);
            cout<<"Enter your full name(name,surname,last name)"<<endl;
            cin>>*name>>*surname>>*last_name;
            foutReader<<*name<<"\t"<<*surname<<"\t"<<*last_name<<"\t"<<newBook<<"\t";
            cout<<"Enter your password"<<endl;
            Reader newReader(*name,*surname,*last_name,*password,newBook);
            foutReader.close();
        }
        finBook.close();
    }
}



int main() {
    delimitation();
    cout<<"Welcome to our library"<<endl;
    cout<<"Choose what you want to do: "<<endl;
    cout<<"1. Administrator"<<endl;
    cout<<"2. Reader"<<endl;
    cout<<"3. Instructions"<<endl;
    cout<<"0. Exit"<<endl;
    delimitation();
    int choice;
    cin>>choice;
    delimitation();
    try{
        if(choice!=1 && choice!=2 && choice!=3 && choice != 0) {
            throw WrongChoice();
        }
            if(choice==1)//Admin
        {
           string password;
           int k=0;
            while (k<3){
                cout<<"Enter password"<<endl;
                cin>>password;
                delimitation();
                if(password=="123") {
                    cout << "Successful access!" << endl;
                    cout<<"Choose what you want to do"<<endl;
                    cout<<"1. Add author and his book"<<endl;
                    cout<<"2. Action 2"<<endl;
                    cout<<"3. Action 3"<<endl;
                    cout<<"0. Exit"<<endl<<endl;
                    int choiceAd;
                    cin>>choiceAd;
                    try {
                        if(choiceAd != 1 && choiceAd != 2 && choiceAd != 3 && choiceAd != 0)
                            throw WrongChoice();
                        switch (choiceAd) {
                            case 1: {
                                addAuthorAndBook();
                                break;
                            }
                            case 2: {
                                bookFromFile();
                                break;
                            }
                            case 3: {
                                break;
                            }
                            case 0: {
                                return 0;
                            }
                                default: {
                                    cout << "Uknown choice" << endl;
                                }
                        }
                        break;
                    }
                    catch (WrongChoice &A){
                        cerr<<A.what();
                    }
                }
                else
                {
                  cout<<"Wrong password"<<endl;
                  k++;
                }
            }
            if(k==3){
                cout<<"You have reached the maximum number of attempts. The program ends."<<endl;
                return 1;
            }

        }
        else if (choice == 2)// Reader
        {
            cout<<"Menu of reader"<<endl;
        }
        else if(choice ==3)//Instructions
        {
            cout<<"Instructions"<<endl;
        }
        else if(choice == 0)
            exit(0);

    }
    catch (WrongPassword &Password){
        cerr<<Password.what();
    }
    return 0;
}
