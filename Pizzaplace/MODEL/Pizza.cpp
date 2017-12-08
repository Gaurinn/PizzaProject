#include "Pizza.h"
#include <stddef.h>
#include <fstream>
using namespace std;

Pizza::Pizza()
{
    //ctor
}
Pizza::~Pizza()
{
    //dtor
}


void Pizza::addTopping(Topping topping){


    toppings.push_back(topping); //
/*
    if(currentToppingNum < toppingCount){
        toppings[currentToppingNum] = topping;
        currentToppingNum++;
    }*/
}

///write to binary file
void Pizza::write(ofstream& fout) const {

    int topCount = toppings.size();

    fout.write((char*)(&topCount), sizeof(int));

    //fout.write((char*) toppings, sizeof(Topping) * toppingCount); //Ploink
    /*
    for(int i = 0; i < topCount; i++){
        fout.write((char*)(&toppings[i]), sizeof(Topping));
    }
    */

    for(int i = 0; i < topCount; i++){
        toppings[i].write(fout);
    }

}
///read from binary file
void Pizza::read(ifstream& fin){

    int topCount;

    fin.read((char*)(&topCount), sizeof(int));

    Topping topping;
    for(int i = 0; i < topCount; i++){
        topping.read(fin);
        addTopping(topping);
    }
    //initialize(topCnt);
    //fin.read((char*) toppings, sizeof(Topping) * toppingCount); //Ploink
    //currentToppingNum = toppingCount;
}

///read from text file
ostream& operator <<(ostream& outs, const Pizza& pizza){

    outs << "Pizza with toppings:" << endl;
    //outs << pizza.toppingCount << " ";
    for(unsigned int i = 0; i < pizza.toppings.size(); i++){
        outs << pizza.toppings[i] << endl;
    }
    return outs;
}
///write to text file
istream& operator >>(istream& ins, Pizza& pizza){

    int toppingCount;
    ins >> toppingCount;

    Topping topping;
    for(unsigned int i = 0; i < pizza.toppings.size(); i++){
        ins >> topping;
        pizza.addTopping(topping);
    }
    return ins;
}

