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

            ToppingUI toppingui;
            toppingui.startUI();

        }
        else if(selection == '2'){ ///PIZZA  MENU menu

            PizzaMenuUI pizzamenuui;
            pizzamenuui.startUI();


        }

        else if(selection == '3'){/// Extra Food menu

            ExtraFoodUI extrafoodui;
            extrafoodui.startUI();


        }

        else if(selection == '4'){///Locations menu

            LocationUI locationui;
            locationui.startUI();


        }
    }
}
