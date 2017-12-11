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


        cout << endl;

        clear();
        cout << "List of all available locations" << endl;
        cout << endl;
        cout << "Press 'q' to go back" << endl;
        cout << endl;
        vector<Location> location = locationRepo.retrieveAllLocations(); //get all locations into a vector
        for(unsigned int i = 0; i < location.size(); i++){            //print from vector
            cout << "[" << i + 1 << "]" << location[i] << endl;
        }
        cout << "Select your location" << endl;
        cin >> selection;
    }
}

        //get list of all pizzas for this location

        //mark pizza as 'not ready' or 'ready'

