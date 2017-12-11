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


        cout << "List of all Locations" << endl;

        cout << "Please select your location" << endl;

        cout << endl;

        cout << endl;
        cout << "Press any key to go back" << endl;
        cout << endl;

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
}
