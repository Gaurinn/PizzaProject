#include "ExtraFood.h"
#include <fstream>

ExtraFood::ExtraFood()
{
    //ctor
}

ExtraFood::ExtraFood(string name, double price)
{
    this->name = name;
    this->price = price;

}
ExtraFood::~ExtraFood()
{
    //dtor
}

void ExtraFood::write(ofstream& fout) const { ///write to binary file
    int stringLength = name.length() + 1;
    fout.write((char*)(&stringLength), sizeof(int)); //write length of name string
    fout.write(name.c_str(), stringLength);          //write name string
    fout.write((char*)(&price), sizeof(double));     //write price
}

void ExtraFood::read(ifstream& fin){ ///read from binary file
    int stringLength;
    fin.read((char*)(&stringLength), sizeof(int));
    char *str = new char[stringLength];
    fin.read(str, stringLength);
    name = str;
    fin.read((char*)(&price), sizeof(double));
    delete[] str;
}

ostream& operator <<(ostream& outs, const ExtraFood& extrafood){
    outs << "Extra Food:    " << extrafood.name << endl;
    outs << "Price:         " << extrafood.price;
    return outs;

}

istream& operator >>(istream& ins, ExtraFood& extrafood){
    cout << "Name of extra food product: ";
    ins >> ws;
    getline(ins, extrafood.name);
    cout << "Price: ";
    ins >> extrafood.price;
    return ins;
}
