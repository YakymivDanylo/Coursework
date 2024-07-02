#include <iostream>
#include <memory>
#include "fstream"
#include <vector>
#include "Reader.h"
#include "Bookstand.h"
#include "Author.h"
#include "Book.h"
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
    ifstream fin(R"("D:\Coursework\Database\Reader.txt")");
    while (fin >> *reader)
        readers.push_back(*reader);
    fin.close();
    return readers;
}

vector<Author> authorFromFile(){
    shared_ptr<Author> author;
    vector<Author> authors;
    ifstream fin(R"("D:\Coursework\Database\Author.txt")");
    while(fin>>*author){
        authors.push_back(*author);
    }
    fin.close();
    return authors;
}

vector<Book> bookFromFile(){
    shared_ptr<Book> book;
    vector<Book> books;
    ifstream fin(R"("D:\Coursework\Database\Books.txt")");
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
    fout<<*newBook;
    fout.close();
}

void addReader(){
    unique_ptr <Reader> newReader {new Reader()};
    cin>>*newReader;
    ofstream fout(R"(D:\Coursework\Database\Reader.txt)",ios_base::app);
    fout<<*newReader;
    fout.close();
}

void addAuthor(){
    unique_ptr<Author> newAuthor {new Author()};
    cin>>*newAuthor;
    ofstream fout(R"("D:\Coursework\Database\Author.txt")",ios_base::app);
    fout<<*newAuthor;
    fout.close();
}

void addBookstand() {
    unique_ptr<Bookstand> newBookstand {new Bookstand()};
    cin>>*newBookstand;
    ofstream fout(R"("D:\Coursework\Database\Bookstands.txt")",ios_base::app);
    fout<<*newBookstand;
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
            cout<<"Enter your password"<<endl;
            Reader newReader(*name,*surname,*last_name,*password,newBook);
            foutReader.close();
        }
        finBook.close();
    }
}



int main() {
    cout<<"Welcome to our library"<<endl;
    cout<<"Choose what you want to do: "<<endl;
    return 0;
}
