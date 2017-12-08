#include "PizzaMenu.h"
#include <stddef.h>
#include <fstream>
using namespace std;

PizzaMenu::PizzaMenu()
{
    //ctor
}
PizzaMenu::PizzaMenu(string name, char size, double price)
{
    //ctor
    this->name = name;
    this->size = size;
    this->price = price;

}
PizzaMenu::~PizzaMenu()
{
    //dtor
}


void PizzaMenu::addTopping(Topping topping){
    toppings.push_back(topping); //
}

///write to binary file
void PizzaMenu::write(ofstream& fout) const {

    int topCount = toppings.size();

    fout.write((char*)(&topCount), sizeof(int));

    for(int i = 0; i < topCount; i++){
        toppings[i].write(fout);
    }
}
///read from binary file
void PizzaMenu::read(ifstream& fin){

    int topCount;

    fin.read((char*)(&topCount), sizeof(int));

    Topping topping;
    for(int i = 0; i < topCount; i++){
        topping.read(fin);
        addTopping(topping);
    }
}
///write from text file
ostream& operator <<(ostream& outs, const PizzaMenu& pizzamenu){

    outs << pizzamenu.name << ",";
    outs << pizzamenu.price << ",";

    //outs << pizza.toppingCount << " ";
    for(unsigned int i = 0; i < pizzamenu.toppings.size(); i++){
        outs << pizzamenu.toppings[i] << ",";
    }
    outs << endl;
    return outs;
}
///write to text file
istream& operator >>(istream& ins, PizzaMenu& pizzamenu){

   // int toppingCount;
    //ins >> toppingCount;

    Topping topping;
    for(unsigned int i = 0; i < pizzamenu.toppings.size(); i++){
        ins >> topping;
        pizzamenu.addTopping(topping);
    }
    return ins;
}

string PizzaMenu::get_name(){

    return name;
}
void PizzaMenu::set_name(string name){

    this->name = name;

}
double PizzaMenu::get_price(){

    return price;
}
void PizzaMenu::set_price(double price){

    this->price = price;

}
