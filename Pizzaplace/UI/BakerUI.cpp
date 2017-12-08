#include "BakerUI.h"
#include <stdio.h>
#include <iostream>
#define clear() printf("\033[H\033[J")
using namespace std;

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::startUI(){
    clear();//clearing screen

    char selection = '\0';

    while(selection != 'q'){
        clear();//clearing screen
        cout << "*****************************************" << endl;
        cout << "\tYou are logged in as Baker staff" << endl;
        cout << "*****************************************" << endl;
        cout << endl;

        ///list all locations and have baker choose his location

        cout << "List all locations" << endl;
        cout << "please pick a location" << endl;
        cout << "List all pizzas for that location" << endl;
        cout << "Choose a pizza" << endl;
        cout << "Mark that pizza as 'in oven or 'ready'" << endl;

        cin >> selection;

        if(selection == 'l'){
            clear();//clearing screen
            cout << "Need to program stuff to make stuff work" << endl;
        }

    }
}
