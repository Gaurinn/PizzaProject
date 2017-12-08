#include "Topping.h"
#include <fstream>

Topping::Topping()
{
    //ctor
}

Topping::Topping(string name, double price)
{
    this->name = name;
    this->price = price;

}
Topping::~Topping()
{
    //dtor
}

string Topping::get_name(){
    return this->name;
}
double Topping::get_price(){
    return this->price;
}

///write to binary file
void Topping::write(ofstream& fout) const {

    int stringLength = name.length() + 1;

    fout.write((char*)(&stringLength), sizeof(int)); //write length of name string
    fout.write(name.c_str(), stringLength);          //write name string

    fout.write((char*)(&price), sizeof(double));     //write price

}
///read from binary file
void Topping::read(ifstream& fin){

    int stringLength;

    fin.read((char*)(&stringLength), sizeof(int));
    char *str = new char[stringLength];

    fin.read(str, stringLength);

    name = str;

    fin.read((char*)(&price), sizeof(double));

    delete[] str;
}

ostream& operator <<(ostream& outs, const Topping& topping){

    outs << topping.name;
   // outs << topping.price;

    return outs;

}

istream& operator >>(istream& ins, Topping& topping){

    cout << "Name: ";
    //ins >> topping.name;

    ins >> ws;
    getline(ins, topping.name);

    cout << "Price: ";
    ins >> topping.price;

    return ins;
}
