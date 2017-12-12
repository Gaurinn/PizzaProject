#include "ExtraFoodUI.h"
#include <iostream>
#include <vector>

#include <stdio.h>
#define clear() printf("\033[H\033[J")
using namespace std;

ExtraFoodUI::ExtraFoodUI()
{
    //ctor
}

ExtraFoodUI::~ExtraFoodUI()
{
    //dtor
}



void ExtraFoodUI::startUI(){

    clear();//clearing screen
    char selection = '\0';
    while(selection != 'c'){
        clear();//clearing screen
        cout << "*****************************************" << endl;
        cout << "\t- Extra Food and Drinks -" << endl;
        cout << "*****************************************" << endl;
        cout << "1: See all Extra Food and Drinks" << endl;
        cout << "2: Add new Extra Food or Drinks" << endl;
        cout << "c: cancel" << endl;
        cin >> selection;

        if(selection == '1'){///see all Extra Food and Drinks
            clear();
            cout << "List of all Extra Food and Drinks" << endl;
            cout << endl;
            cout << "Press any key to go back" << endl;
            cout << endl;

            if(selection == '1'){///see all extra food
                clear();
                cout << "List of all available extra food" << endl;
                cout << endl;
                cout << "Press any key to go back" << endl;
                cout << endl;
                vector<ExtraFood> extrafood = extrafoodservice.retrieveAllExtraFoodService(); //get all toppings into a vector
                for(unsigned int i = 0; i < extrafood.size(); i++){            //print from vector
                    cout << "[" << i + 1 << "]" << extrafood[i] << "kr." << endl;
                }
                cin >> selection;
            }
        }
        else if(selection == '2'){///add new Extra Food or Drink
            selection = 'y';
            while(selection == 'y'){
                clear();
                cout << "Making new Extra Food or Drink" << endl;
                cout << endl;
                ExtraFood extrafood;
                while(selection == 'y'){
                    cin >> extrafood;
                    extrafoodservice.storeExtraFoodService(extrafood);
                    cout << "Add more extra food (y)?";
                    cin >> selection;
                }
            }
        }
    }
}
