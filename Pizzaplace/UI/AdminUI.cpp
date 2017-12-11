#include "AdminUI.h"
#include "../MODEL/ExtraFood.h"
#include "../MODEL/Topping.h"
#include "../MODEL/PizzaMenu.h"
#include "../SERVICE/ToppingService.h"
#include "PizzaMenuService.h"
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
        cout << "[1]: Toppings" << endl;
        cout << "[2]: Pizza Menu" << endl;
        cout << "[3]: Extra Food & drinks" << endl;
        cout << "[4]: Locations" << endl;
        cout << "q: quit" << endl;

        cin >> selection;


        if(selection == '1'){ ///Topping Menu
            clear();//clearing screen
           // char input = '\0';
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
                    vector<Topping> toppings = toppingRepo.retrieveAllToppings(); //get all toppings into a vector
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
        else if(selection == '2'){ ///PIZZA  MENU menu
            clear();//clearing screen
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


                    ///add stuff to see all menu pizzas
                    vector<PizzaMenu> pizzamenu = pizzaMenuService.retrieveAllMenu();
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
                        vector<Topping> toppings = toppingRepo.retrieveAllToppings(); //get all toppings into a vector
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
                        pizzaMenuRepo.storePizzaMenu(pizzamenu); //store new menu pizza

                        cout << "Your new Menu pizza : " << "\"" << pizzamenu.get_name() << "\" " << " - - - - - " << pizzamenu.get_price() << "kr." << endl;
                        cout << endl;
                        cout << "Add another Pizza to Menu? (y/n)" << endl;
                        cin >> selection;
                    }
                }
            }
        }

        else if(selection == '3'){/// Extra Food menu
            clear();//clearing screen
            while(selection != 'c'){
                clear();//clearing screen
                cout << "*****************************************" << endl;
                cout << "\t- Extra Food and Drinks -" << endl;
                cout << "*****************************************" << endl;
                cout << "1: See all Extra Food and Drinks" << endl;
                cout << "2: Add new Extra Food or Drinks" << endl;
                cout << "c: cancel" << endl;
                cin >> selection;

                if(selection == '1'){///see all Extra Food and Drinks
                    clear();
                    cout << "List of all Extra Food and Drinks" << endl;
                    cout << endl;
                    cout << "Press any key to go back" << endl;
                    cout << endl;

                    if(selection == '1'){///see all extra food
                        clear();
                        cout << "List of all available extra food" << endl;
                        cout << endl;
                        cout << "Press any key to go back" << endl;
                        cout << endl;
                        vector<ExtraFood> extrafood = extraFoodRepo.retrieveAllExtraFood(); //get all toppings into a vector
                        for(unsigned int i = 0; i < extrafood.size(); i++){            //print from vector
                            cout << "[" << i + 1 << "]" << extrafood[i] << "kr." << endl;
                        }
                        cin >> selection;
                    }
                }
                else if(selection == '2'){///add new Extra Food or Drink
                    selection = 'y';
                    while(selection == 'y'){
                        clear();
                        cout << "Making new Extra Food or Drink" << endl;
                        cout << endl;
                        ExtraFood extrafood;
                        while(selection == 'y'){
                            cin >> extrafood;
                            extraFoodRepo.storeExtraFood(extrafood);
                            cout << "Add more extra food (y)?";
                            cin >> selection;
                        }
                    }
                }
            }
        }

        else if(selection == '4'){///Locations menu
            clear();//clearing screen
            while(selection != 'c'){
                clear();//clearing screen
                cout << "*****************************************" << endl;
                cout << "\t\t- Locations -" << endl;
                cout << "*****************************************" << endl;
                cout << "1: See all Locations" << endl;
                cout << "2: Add new Location" << endl;
                cout << "c: cancel" << endl;
                cin >> selection;

                if(selection == '1'){///see all Locations
                    clear();
                    cout << "List of all Locations" << endl;
                    cout << endl;
                    cout << "Press any key to go back" << endl;
                    cout << endl;

                    if(selection == '1'){///see all locations
                        clear();
                        cout << "List of all available locations" << endl;
                        cout << endl;
                        cout << "Press any key to go back" << endl;
                        cout << endl;
                        vector<Location> location = locationRepo.retrieveAllLocations(); //get all locations into a vector
                        for(unsigned int i = 0; i < location.size(); i++){            //print from vector
                            cout << "[" << i + 1 << "]" << location[i] << endl;
                        }
                        cin >> selection;
                    }

                    cin >> selection;
                }
                else if(selection == '2'){///add new Location
                    selection = 'y';
                    while(selection == 'y'){
                        clear();
                        cout << "Making new Location" << endl;
                        cout << endl;
                        Location location; //making a new location
                        while(selection == 'y'){
                            cin >> location;
                            locationRepo.storeLocation(location);
                            cout << "Add more locations (y)?";
                            cin >> selection;
                        }
                    }
                }
            }
        }
    }
}
