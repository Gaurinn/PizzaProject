#include "PizzaMenuRepository.h"
#include <fstream>
#include "../MODEL/PizzaMenu.h"
#include <iostream>

using namespace std;


PizzaMenuRepository::PizzaMenuRepository()
{
    //ctor
}

PizzaMenuRepository::~PizzaMenuRepository()
{
    //dtor
}


void PizzaMenuRepository::storePizzaMenu(const PizzaMenu& pizzamenu){       ///store pizza to binary file

    //Store pizza to text tile
    ofstream fout;
    fout.open("PizzaMenu.txt", ios::app);
    fout << pizzamenu;
    fout.close();

/*
    ofstream fout;
    fout.open("pizzaMenuBinary.bin", ios::binary|ios::app);
    pizzamenu.write(fout);
    fout.close();
*/
}

PizzaMenu PizzaMenuRepository::retrievePizzaMenu(){                         ///read pizza from binary file

    ifstream fin;
    fin.open("pizzaMenuBinary.bin", ios::binary);

    PizzaMenu pizzamenu;
    pizzamenu.read(fin);
    fin.close();

    return pizzamenu;
}

vector<PizzaMenu> PizzaMenuRepository::retrieveAllPizzasMenu(){              ///read all pizzas from binary file

///text file
    vector<PizzaMenu> pizzamenu;



        string str;
        ifstream fin;
        fin.open("PizzaMenu.txt");

        if(fin.is_open()){
            while(!fin.eof()){
                getline(fin, str);
                cout << str << endl;
            }
        }



    else {
        cout << "Could not open file" << endl;
    }

    fin.close();


    return pizzamenu;
}

