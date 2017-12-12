#include "ToppingUI.h"
#include "Topping.h"
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <vector>
#define clear() printf("\033[H\033[J")
using namespace std;


ToppingUI::ToppingUI()
{
    //ctor
}

ToppingUI::~ToppingUI()
{
    //dtor
}

void ToppingUI::startUI(){

    clear();//clearing screen
    char selection = '\0';
    while(selection != 'c'){
        clear();//clearing screen
        cout << "*****************************************" << endl;
        cout << "\t\t- Toppings -" << endl;
        cout << "*****************************************" << endl;
        cout << "1: see all toppings" << endl;
        cout << "2: add new toppings" << endl;
        cout << "c: cancel" << endl;
        cin >> selection;

        if(selection == '1'){///see all toppings
            clear();
            cout << "List of all available toppings" << endl;
            cout << endl;
            cout << "Press any key to go back" << endl;
            cout << endl;
            vector<Topping> toppings = toppingservice.retrieveAllToppingsService(); //get all toppings into a vector
            for(unsigned int i = 0; i < toppings.size(); i++){            //print from vector
                cout << "[" << i + 1 << "]" << toppings[i] << "- - - - - " << toppings[i].get_price() << "kr." << endl;
            }
            cin >> selection;
        }
        else if(selection == '2'){///add new toppings
            selection = 'y';
            while(selection == 'y'){
                clear();
                cout << "Making a new topping" << endl;
                Topping topping; //making a new instance of topping
                cin >> topping;
                toppingservice.storeTopping(topping); //storing topping
                cout << "Add another topping? (y/n)" << endl;
                cin >> selection;
            }
        }
    }

}
