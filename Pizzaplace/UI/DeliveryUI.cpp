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
        cout << "   You are logged in as Delivery staff" << endl;
        cout << "*****************************************" << endl;
        cout << endl;

        ///list all locations and have delivery staff choose his location

        //get list of all orders for this location

        //get list of all order marked as ready for this location


        cin >> selection;

    }
}
