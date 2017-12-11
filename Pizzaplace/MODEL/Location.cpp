#include "Location.h"
#include <fstream>

Location::Location()
{
    //ctor
}

Location::Location(string name, int phone)
{
    this->name = name;
    this->phone = phone;
}
Location::~Location()
{
    //dtor
}

void Location::write(ofstream& fout) const { ///write to binary file
    int stringLength = name.length() + 1;
    fout.write((char*)(&stringLength), sizeof(int)); //write length of name string
    fout.write(name.c_str(), stringLength);          //write name string
    fout.write((char*)(&phone), sizeof(int));     //write phone
}

void Location::read(ifstream& fin){ ///read from binary file
    int stringLength;
    fin.read((char*)(&stringLength), sizeof(int));
    char *str = new char[stringLength];
    fin.read(str, stringLength);
    name = str;
    fin.read((char*)(&phone), sizeof(int));
    delete[] str;
}

ostream& operator <<(ostream& outs, const Location& location){
    outs << location.name << " - - - - - Phone number: " << location.phone;
    return outs;

}

istream& operator >>(istream& ins, Location& location){
    cout << "Name of new location: ";
    ins >> ws;
    getline(ins, location.name);
    cout << "Phone number: ";
    ins >> location.phone;
    return ins;
}

string Location::get_name(){

    return name;
}
void Location::set_name(string name){

    this->name = name;

}
double Location::get_phone(){

    return phone;
}
void Location::set_phone(int phone){

    this->phone = phone;

}

