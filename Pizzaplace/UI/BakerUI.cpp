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
        cout << "[#]: Please pick a location" << endl;
        cout << endl;
        cout << "Press 'q' to go back" << endl;
        cout << endl;
        vector<Location> location = locationRepo.retrieveAllLocations(); //get all locations into a vector
        for(unsigned int i = 0; i < location.size(); i++){            //print from vector
            cout << "[" << i + 1 << "]" << location[i] << endl;
        }
        cout << "Select your location" << endl;
        cin >> selection;


        clear();
        cout << "Please pick an order" << endl;
        ///list all orders for selected location

        ///pick an order from that list
        cin >> selection;

        cout << "Please pick a pizza to bake" << endl;
        ///list all pizzas in selected order

        ///pick a pizza from that list to be marked as is_ready
        cin >> selection;

    }
}



