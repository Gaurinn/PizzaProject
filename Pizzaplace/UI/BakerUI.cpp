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

        //get list of all pizzas for this location

        //mark pizza as 'not ready' or 'ready'

        cin >> selection;

    }
}
