//
// Created by danyl on 27.06.2024.
//

#include "Reader.h"
Reader::Reader()
    : Person(),idR(), books(){
write_log();
}

Reader::Reader(string name, string surname, string last_name,int idR ,Book book)
    : Person(name, surname, last_name),idR(idR) ,books(book)
    {
write_log();
    }

    Reader::~Reader() noexcept {
        ofstream foutLog(R"(D:\Coursework\Database\Logs.txt)",ios_base::app);
        auto now = chrono::system_clock::now();
        time_t log_time = chrono::system_clock::to_time_t(now);
        foutLog<<ctime(&log_time)<<"\t::\t"
        <<"Reader object was deleted."<<endl;
}

ostream &operator<<(ostream &os,  Reader &obj){
    os << static_cast<const Person&>(obj) <<" "<<obj.idR<<" ";
    os<<obj.books<<endl;
    return os;
}
istream &operator>>(istream &is,Reader &obj ){
    is>>static_cast< Person&>(obj)>>obj.idR;
    is>>obj.books;
    return is;
}

Reader &Reader::operator=(const Reader &rhs) {
    if (this!=&rhs){
        this->name=rhs.name;
        this->surname=rhs.surname;
        this->last_name=rhs.last_name;
        this->idR=rhs.idR;
        this->books=rhs.books;
    }
    return *this;
}

Reader::Reader(const Reader &other)
: Person(other),idR(other.idR) ,books(other.books){}

Reader::Reader(Reader &&other)
: Person(other),idR(other.idR) ,books(other.books){
    other.name="unknown";
    other.surname="unknown";
    other.last_name="unknown";
    other.idR=0;
    other.books=Book();
}

string Reader::getName() {return name;}
string Reader::getSurname() {return surname;}
string Reader::getLastName() {return  last_name;}
int Reader::getID() {return  idR;}
Book Reader::getBook() {return books;}

void Reader::write_to_a_file() {
    ofstream fout(R"(D:\Coursework\Database\Reader.txt)",ios_base::app);
    fout<<name<<"\t"<<surname<<"\t"<<last_name<<"\t"<<idR<<"\t"<<books<<endl;
    fout.close();
}

bool Reader::search() {
    ifstream fin(R"(D:\Coursework\Database\Reader.txt)");
    Book book;
    Reader reader;
    while (fin>>reader){
        if(reader.name==name && reader.surname==surname && reader.last_name==last_name && reader.idR == idR)
            return true;
    }
    return false;
}

void Reader::getReader() const {
    cout<<"Name: "<<name<<" Surname: "<<surname<<" Last name:"<<last_name<<"ID of reader"<<idR<<" ";
    books.getBook();
}

int Reader::getId() {return  books.getId();}

void Reader::write_log() {
    ofstream foutLog(R"(D:\Coursework\Database\Logs.txt)",ios_base::app);
    auto now = chrono::system_clock::now();
    time_t log_time = chrono::system_clock::to_time_t(now);
    foutLog<<ctime(&log_time)<<"\t::\t"
    <<"Reader object was created with parameters: "<<endl
    <<"\tname: "<<name<<endl
    <<"\tsurname: "<<surname<<endl
    <<"\tlastname: "<<last_name<<endl
    <<"\tID: "<<idR<<endl;
}

