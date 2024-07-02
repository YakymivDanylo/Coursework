//
// Created by danyl on 27.06.2024.
//

#include "Reader.h"
Reader::Reader()
    :People(),password("uknown"),books(){}

Reader::Reader(string name, string surname, string last_name,string password, Book book)
    :People(name,surname,last_name),books(book),password(password) {}

    Reader::~Reader() noexcept {
    cout<<name<<" "<<surname<<" "<<last_name<<" "<<"was deleted";
}

ostream &operator<<(ostream &os,  Reader &obj){
    os<<static_cast<const People&>(obj)<<"\t"<<obj.password;
    os<<obj.books<<endl;
    return os;
}
istream &operator>>(istream &is,Reader &obj ){
    is>>static_cast< People&>(obj);
    is>>obj.password;
    is>>obj.books;
    return is;
}

Reader &Reader::operator=(const Reader &rhs) {
    if (this!=&rhs){
        this->name=rhs.name;
        this->surname=rhs.surname;
        this->last_name=rhs.last_name;
        this->password=rhs.password;
        this->books=rhs.books;
    }
    return *this;
}

Reader::Reader(const Reader &other)
: People(other),books(other.books),password(other.password){}

Reader::Reader(Reader &&other)
: People(other),books(other.books),password(other.password){
    other.name="unknown";
    other.surname="unknown";
    other.last_name="unknown";
    other.password="unknown";
    other.books=Book();
}

string Reader::getName() {return name;}
string Reader::getSurname() {return surname;}
string Reader::getLastName() {return  last_name;}
string Reader::getPassword() {return password;}
Book Reader::getBook() {return books;}

void Reader::write_to_a_file() {
    ofstream fout(R"(D:\Coursework\Database\Reader.txt)",ios_base::app);
    fout<<name<<"\t"<<surname<<"\t"<<last_name<<"\t"<<password<<"\t"<<books<<endl;
    fout.close();
}

bool Reader::search() {
    ifstream fin(R"(D:\Coursework\Database\Reader.txt)");
    Book book;
    Reader reader;
    while (fin>>reader){
        if(reader.name==name && reader.surname==surname && reader.last_name==last_name && reader.password==password)
            return true;
    }
    return false;
}

void Reader::getReader() const {
    cout<<"Name: "<<name<<" Surname: "<<surname<<" Last name:"<<last_name<<endl;
    books.getBook();
}



