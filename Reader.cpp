//
// Created by danyl on 27.06.2024.
//

#include "Reader.h"
Reader::Reader()
    : Person(), books(){
//    Reader reader;
//    Book book;
//    ofstream fout(R"(D:\Coursework\Database\Constructors_and_Destructors.txt)");
//    fout<<reader<<endl;
//    fout.close();
}

Reader::Reader(string name, string surname, string last_name, Book book)
    : Person(name, surname, last_name), books(book)
    {
//        Reader reader;
//        ofstream fout(R"(D:\Coursework\Database\Constructors_and_Destructors.txt)");
//        fout<<reader<<endl;
//        fout.close();
    }

    Reader::~Reader() noexcept {
//    cout<<name<<" "<<surname<<" "<<last_name<<" "<<"was deleted"<<endl;
//        Reader reader;
//        Book book;
//        ofstream fout(R"(D:\Coursework\Database\Constructors_and_Destructors.txt)");
//        fout<<reader<<" was deleted"<<endl;
//        fout.close();
}

ostream &operator<<(ostream &os,  Reader &obj){
    os << static_cast<const Person&>(obj) <<" ";
    os<<obj.books<<endl;
    return os;
}
istream &operator>>(istream &is,Reader &obj ){
    is>>static_cast< Person&>(obj);
    is>>obj.books;
    return is;
}

Reader &Reader::operator=(const Reader &rhs) {
    if (this!=&rhs){
        this->name=rhs.name;
        this->surname=rhs.surname;
        this->last_name=rhs.last_name;
        this->books=rhs.books;
    }
    return *this;
}

Reader::Reader(const Reader &other)
: Person(other), books(other.books){}

Reader::Reader(Reader &&other)
: Person(other), books(other.books){
    other.name="unknown";
    other.surname="unknown";
    other.last_name="unknown";
    other.books=Book();
}

string Reader::getName() {return name;}
string Reader::getSurname() {return surname;}
string Reader::getLastName() {return  last_name;}
Book Reader::getBook() {return books;}

void Reader::write_to_a_file() {
    ofstream fout(R"(D:\Coursework\Database\Reader.txt)",ios_base::app);
    fout<<name<<"\t"<<surname<<"\t"<<last_name<<"\t"<<books<<endl;
    fout.close();
}

bool Reader::search() {
    ifstream fin(R"(D:\Coursework\Database\Reader.txt)");
    Book book;
    Reader reader;
    while (fin>>reader){
        if(reader.name==name && reader.surname==surname && reader.last_name==last_name)
            return true;
    }
    return false;
}

void Reader::getReader() const {
    cout<<"Name: "<<name<<" Surname: "<<surname<<" Last name:"<<last_name<<endl;
    books.getBook();
}



