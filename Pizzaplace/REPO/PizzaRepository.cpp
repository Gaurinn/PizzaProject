#include "PizzaRepository.h"
#include <fstream>
#include "../MODEL/Pizza.h"
#include <iostream>

using namespace std;

PizzaRepository::PizzaRepository()
{
    //ctor
}

PizzaRepository::~PizzaRepository()
{
    //dtor
}

void PizzaRepository::storePizza(const Pizza& pizza){

/*Store pizza to text tile
    ofstream fout;
    fout.open("Pizzas.txt");
    fout << pizza;
    fout.close();
*/


///store pizza to binary file
    ofstream fout;
    fout.open("pizzaBinary.bin", ios::binary|ios::app);
    pizza.write(fout);
    fout.close();
}

Pizza PizzaRepository::retrievePizza(){
/* Read pizza from text file
    ifstream fin;
    fin.open("Pizzas.txt");
    Pizza pizza;
    fin >> pizza;
    fin.close();
    return pizza;
*/

///read pizza from binary file
    ifstream fin;
    fin.open("pizzaBinary.bin", ios::binary);

    Pizza pizza;
    pizza.read(fin);
    fin.close();

    return pizza;
}

vector<Pizza> PizzaRepository::retrieveAllPizzas(){


    ///read all pizzas from binary file

    vector<Pizza> pizzas;

    ifstream fin;
    fin.open("pizzaBinary.bin", ios::binary);

    Pizza pizza;

    while(true){

        int filePos = fin.tellg();          //current position in file
        fin.seekg(0, fin.end);              //go to end

        int endPos = fin.tellg();           //end position in file

        if((endPos - filePos) <= 1){        //if true last record read... not enough space left for whole record
            break;
        }

        fin.seekg(filePos);
        pizza.read(fin);
        pizzas.push_back(pizza);

    }
    fin.close();

    return pizzas;

}





