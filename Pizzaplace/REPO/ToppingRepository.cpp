#include "ToppingRepository.h"
#include <fstream>

ToppingRepository::ToppingRepository()
{
    //ctor
}

ToppingRepository::~ToppingRepository()
{
    //dtor
}

void ToppingRepository::storeTopping(const Topping& topping){

///store topping to binary file
    ofstream fout;
    fout.open("toppingsBinary.bin", ios::binary|ios::app);

    topping.write(fout);

    fout.close();


}

Topping ToppingRepository::retrieveTopping(){

///read topping from binary file
    ifstream fin;
    fin.open("toppingsBinary.bin", ios::binary);

    Topping topping;
    topping.read(fin);
    fin.close();

    return topping;

}


vector<Topping> ToppingRepository::retrieveAllToppings(){


    ///read all toppings from binary file

    vector<Topping> toppings;

    ifstream fin;
    fin.open("toppingsBinary.bin", ios::binary);

    Topping topping;

    while(true){

        int filePos = fin.tellg();          //current position in file
        fin.seekg(0, fin.end);              //go to end

        int endPos = fin.tellg();           //end position in file

        if((endPos - filePos) <= 1){        //if true last record read... not enough space left for whole record
            break;
        }

        fin.seekg(filePos);
        topping.read(fin);
        toppings.push_back(topping);

    }
    fin.close();

    return toppings;

}




