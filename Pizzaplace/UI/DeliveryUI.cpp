#include "DeliveryUI.h"
#include <stdio.h>
#include <iostream>
#define clear() printf("\033[H\033[J")
using namespace std;

DeliveryUI::DeliveryUI()
{
    //ctor
}

void DeliveryUI::startUI(){
    clear();//clearing screen

    char selection = '\0';

    while(selection != 'q'){
        clear();//clearing screen
        cout << "*****************************************" << endl;
        cout << "\tYou are logged in as Delivery staff" << endl;
        cout << "*****************************************" << endl;
        cout << endl;

        ///list all locations and have delivery staff choose his location

        cout << "List all locations" << endl;
        cout << "please pick a location" << endl;
        cout << "List all orders for that location that have status 'ready'" << endl;
        cout << "Choose an order" << endl;
        cout << "Mark that order as 'delivered'" << endl;

        cin >> selection;

        if(selection == 'l'){
            clear();//clearing screen
            cout << "Need to program stuff to make stuff work" << endl;
        }

    }
}
