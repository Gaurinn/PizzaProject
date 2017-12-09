#include "SalesUI.h"
#include "OrderUI.h"
#include <stdio.h>
#include <iostream>
#define clear() printf("\033[H\033[J")
using namespace std;

SalesUI::SalesUI()
{
    //ctor
}

void SalesUI::startUI(){
    clear();//clearing screen

    char selection = '\0';

    while(selection != 'q'){
        clear();//clearing screen
        cout << "*****************************************" << endl;
        cout << "\tYou are logged in as Sales Staff" << endl;
        cout << "*****************************************" << endl;
        cout << endl;
        cout << "[1]: Make a new order" << endl;
        cout << "q: quit" << endl;

        cin >> selection;


        if(selection == '1'){ ///Make a new Order
            ///open orderUI
            OrderUI orderui;
            orderui.startUI();
        }

    }
}
