#include "LocationUI.h"
#include <iostream>
#include "Location.h"
#include <stdio.h>
#include <vector>
#define clear() printf("\033[H\033[J")
using namespace std;

LocationUI::LocationUI()
{
    //ctor
}

LocationUI::~LocationUI()
{
    //dtor
}



void LocationUI::startUI(){
    clear();//clearing screen
    char selection = '\0';
    while(selection != 'c'){
        clear();//clearing screen
        cout << "*****************************************" << endl;
        cout << "\t\t- Locations -" << endl;
        cout << "*****************************************" << endl;
        cout << "1: See all Locations" << endl;
        cout << "2: Add new Location" << endl;
        cout << "c: cancel" << endl;
        cin >> selection;

        if(selection == '1'){///see all Locations
            clear();
            cout << "List of all Locations" << endl;
            cout << endl;
            cout << "Press any key to go back" << endl;
            cout << endl;

            if(selection == '1'){///see all locations
                clear();
                cout << "List of all available locations" << endl;
                cout << endl;
                cout << "Press any key to go back" << endl;
                cout << endl;
                vector<Location> location = locationservice.retrieveAllLocationsService(); //get all locations into a vector
                for(unsigned int i = 0; i < location.size(); i++){            //print from vector
                    cout << "[" << i + 1 << "]" << location[i] << endl;
                }
                cin >> selection;
            }

            cin >> selection;
        }
        else if(selection == '2'){///add new Location
            selection = 'y';
            while(selection == 'y'){
                clear();
                cout << "Making new Location" << endl;
                cout << endl;
                Location location; //making a new location
                while(selection == 'y'){
                    cin >> location;
                    locationservice.storeLocationService(location);
                    cout << "Add more locations (y)?";
                    cin >> selection;
                }
            }
        }
    }
}
