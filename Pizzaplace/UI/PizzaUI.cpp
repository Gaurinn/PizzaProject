#include "PizzaUI.h"
#include "../MODEL/Pizza.h"
#include "../MODEL/Topping.h"
#include <iostream>
using namespace std;

PizzaUI::PizzaUI()
{
    //ctor
}


void PizzaUI::startUI(){



    cout << "m: make pizza" << endl;
    cout << "r: read pizza" << endl;
    cout << "t: add toppings" << endl;

    char selection;
    cin >> selection;


    if(selection == 'm'){ ///Make Pizza

        vector<Topping> toppings = toppingRepo.retrieveAllToppings(); //get all toppings

        Pizza pizza; // create a new pizza to add toppings to

        int toppingSelection = -1;

        while(toppingSelection != 0){

            cout << "Please enter topping ID to add topping to pizza (0  for no more toppings)" << endl;

            for(unsigned int i = 0; i < toppings.size(); i++){

                cout << "[" << i + 1 << "]" << toppings[i] << endl;
            }

            cin >> toppingSelection;

            if(toppingSelection > 0 && toppingSelection <= (int)toppings.size()){ //if topping selection is between 1 and number of toppings available

                pizza.addTopping(toppings[toppingSelection - 1]);
            }

        }
        cout << pizza << endl;

        pizzaRepo.storePizza(pizza);

        cout << endl;
    }

    else if(selection == 'r'){

        vector<Pizza> pizzas = pizzaRepo.retrieveAllPizzas();

        //Pizza pizza;

        for(unsigned int i = 0; i < pizzas.size(); i++){

            cout << "[" << i + 1 << "]" << pizzas[i] << endl;
        }






/*
        Pizza pizza = pizzaRepo.retrievePizza();

        cout << pizza;
        cout << endl;*/
    }
    else if(selection == 't'){

        char selection = 'y';

        Topping topping;

        while(selection == 'y'){
            cin >> topping;
            toppingRepo.storeTopping(topping);

            cout << "Add another topping (y)?";
            cin >> selection;
        }
    }
}
