#include "AdminUI.h"
#include "../MODEL/ExtraFood.h"
#include "../MODEL/Topping.h"
#include "../MODEL/PizzaMenu.h"
#include "../SERVICE/ToppingService.h"
//#include "../REPO/PizzaMenuRepository.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

#include <stdio.h>
#define clear() printf("\033[H\033[J")


AdminUI::AdminUI()
{
    //ctor
}

void AdminUI::startUI(){
    clear();//clearing screen

    char selection = '\0';

    while(selection != 'q'){
        clear();//clearing screen
        cout << "*****************************************" << endl;
        cout << "\tYou are logged in as Admin" << endl;
        cout << "*****************************************" << endl;
        cout << endl;
        cout << "t: add new toppings" << endl;
        cout << "r: read all toppings" << endl;
        cout << "m: add a new Menu Pizza" << endl;
        cout << "e: add extra food (sodas, breadsticks, etc.)" << endl;
        cout << "l: add a pickup location" << endl;
        cout << "q: quit" << endl;

        cin >> selection;


        if(selection == 't'){ ///ADD NEW TOPPING
            clear();//clearing screen
            char selection = 'y';
            Topping topping;
            while(selection == 'y'){
                clear();
                cout << "Making a new topping" << endl;
                cin >> topping;
                toppingservice.storeTopping(topping);
                cout << "Add another topping (y)?";
                cin >> selection;
            }
        }
        else if(selection == 'r'){ ///see all toppings
            clear();//clearing screen
            char selection = 'y';
            while(selection == 'y'){
                PizzaMenu pizzamenu; // create a new pizza to add toppings to


                vector<Topping> toppings = toppingRepo.retrieveAllToppings(); //get all toppings

                cout << "List of all available toppings" << endl;
                cout << endl;

                for(unsigned int i = 0; i < toppings.size(); i++){

                    cout << toppings[i] << " " << toppings[i].get_price() << endl;
                }

                cin >> selection;


            }
        }
        else if(selection == 'm'){ ///ADD NEW PIZZA TO MENU
            clear();//clearing screen
            char selection = 'y';
            while(selection == 'y'){
                PizzaMenu pizzamenu; // create a new pizza to add toppings to

                string pName;
                cout << "Enter name of menu pizza" << endl;
                cin >> pName;
                pizzamenu.set_name(pName);

                vector<Topping> toppings = toppingRepo.retrieveAllToppings(); //get all toppings

                int toppingSelection = -1;
                while(toppingSelection != 0){
                    cout << "Please enter topping ID to add topping to pizza (0  for no more toppings)" << endl;
                    for(unsigned int i = 0; i < toppings.size(); i++){

                        cout << "[" << i + 1 << "]" << toppings[i] << endl;
                    }
                    cin >> toppingSelection;

                    if(toppingSelection > 0 && toppingSelection <= (int)toppings.size()){ //if topping selection is between 1 and number of toppings available

                        pizzamenu.addTopping(toppings[toppingSelection - 1]);
                    }
                }

                double pPrice;
                cout << "Enter price for menu pizza" << endl;
                cin >> pPrice;
                pizzamenu.set_price(pPrice);

                cout << "Your new Menu pizza : " << pizzamenu.get_name() << endl;
                pizzaMenuRepo.storePizzaMenu(pizzamenu);
                cout << endl;

                cout << "Add another Pizza to menu (y)?";
                cin >> selection;
            }
        }

        else if(selection == 'e'){///Make Extra Food

            char selection = 'y';

            ExtraFood extrafood;
            while(selection == 'y'){
                cin >> extrafood;
                extraFoodRepo.storeExtraFood(extrafood);
                cout << "Add more extra food (y)?";
                cin >> selection;
            }

        }

        else if(selection == 'l'){
            char selection = 'y';

            Location location;
            while(selection == 'y'){
                cin >> location;
                locationRepo.storeLocation(location);
                cout << "Add more locations (y)?";
                cin >> selection;
            }
        }
    }
}
