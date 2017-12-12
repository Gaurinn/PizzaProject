#include "PizzaMenuUI.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#define clear() printf("\033[H\033[J")
using namespace std;


PizzaMenuUI::PizzaMenuUI()
{
    //ctor
}

PizzaMenuUI::~PizzaMenuUI()
{
    //dtor
}



void PizzaMenuUI::startUI(){

    clear();//clearing screen
    char selection = '\0';
    while(selection != 'c'){
        clear();//clearing screen
        cout << "*****************************************" << endl;
        cout << "\t\t- Pizza Menu -" << endl;
        cout << "*****************************************" << endl;
        cout << "1: See Menu" << endl;
        cout << "2: Add new Pizza to Menu" << endl;
        cout << "c: cancel" << endl;
        cin >> selection;

        if(selection == '1'){///see all Menu Pizza
            clear();
            cout << "List of all Pizzas on Menu" << endl;
            cout << endl;
            cout << "Press any key to go back" << endl;
            cout << endl;


            vector<PizzaMenu> pizzamenu = pizzamenuservice.retrieveAllMenu();
            for(unsigned int i = 0; i < pizzamenu.size(); i++){
                cout << "[" << i + 1 << "]" << pizzamenu[i] << endl;
            }



            cin >> selection;
        }
        else if(selection == '2'){///add new Pizza to Menu
            selection = 'y';
            while(selection == 'y'){
                clear();
                cout << "Making a new Pizza to add to Menu" << endl;
                cout << endl;
                cout << "Enter name of menu pizza" << endl;

                PizzaMenu pizzamenu; // create a new pizza to add toppings to
                string pName;
                cin >> pName;
                pizzamenu.set_name(pName);//set name of new Menu Pizza
                vector<Topping> toppings = toppingservice.retrieveAllToppingsService(); //get all toppings into a vector
                int toppingSelection = -1;
                int toppingCount = 0;
                while(toppingSelection != 0){
                    clear();
                    cout << "Please enter topping ID to add topping to pizza (0  for no more toppings)" << endl;
                    cout << "Your new Pizza \"" << pizzamenu.get_name() << "\" currently has " << toppingCount << " toppings" << endl;
                    for(unsigned int i = 0; i < toppings.size(); i++){
                        cout << "[" << i + 1 << "]" << toppings[i] << endl; // print all toppings in vector
                    }
                    cin >> toppingSelection;

                    if(toppingSelection > 0 && toppingSelection <= (int)toppings.size()){ //if topping selection is between 1 and number of toppings available
                        pizzamenu.addTopping(toppings[toppingSelection - 1]); //add topping to pizza
                        toppingCount++;
                    }
                }

                double pPrice;
                cout << "Enter price for new Menu Pizza \"" << pizzamenu.get_name() << "\"" << endl;
                cin >> pPrice;
                pizzamenu.set_price(pPrice); //set price for new menu pizza
                pizzamenuservice.storePizzaMenuService(pizzamenu); //store new menu pizza

                cout << "Your new Menu pizza : " << "\"" << pizzamenu.get_name() << "\" " << " - - - - - " << pizzamenu.get_price() << "kr." << endl;
                cout << endl;
                cout << "Add another Pizza to Menu? (y/n)" << endl;
                cin >> selection;
            }
        }
    }
}
