#include "DeliveryUI.h"
#include <stdio.h>
#include <iostream>
#include <stdio.h>

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


        clear();//clearing screen
        cout << "Would you like to make a delivery or work the cash register?" << endl;
        cout << endl;

        cout << "[1]: Make a delivery" << endl;
        cout << "[2]: Work the cash register" << endl;

        cout << "q: quit" << endl;

        cin >> selection;

        if(selection == '1'){
            cout << "Please pick an order to deliver" << endl;
        ///list all orders for selected location that are marked as is_ready=true and pickup=false

        ///pick an order from that list

        ///mark that order as paid (and delivered)
            cin >> selection;

        }
        else if(selection == '2'){
            cout << "Please pick an order to deliver to a pickup customer" << endl;
        ///list all orders for selected location that are marked as pickup=true

        ///pick an order from that list

        ///mark that order as paid
            cin >> selection;
        }
    }
}
