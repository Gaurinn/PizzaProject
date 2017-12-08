#include "SalesUI.h"
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
        cout << "\tYou are logged in as Sales staff" << endl;
        cout << "*****************************************" << endl;
        cout << endl;
        cout << "o: make a new order" << endl;
        cout << "a: add to an order" << endl;
        cout << "g: get price of an order" << endl;
        cout << "d: mark an order as ready" << endl;
        cout << "q: quit" << endl;

        cin >> selection;

        if(selection == 'o'){ ///Make a new order
            clear();//clearing screen
            cout << "Need to program stuff to make an order" << endl;
        }
        else if(selection == 'm'){ ///ADD to an order
            clear();//clearing screen
            cout << "Need to program stuff to add to an order" << endl;
        }

        else if(selection == 'e'){///Get price for an order
            clear();
            cout << "Need to program stuff to get price for an order" << endl;
        }

        else if(selection == 'l'){
           clear();
           cout << "Need to program stuff to mark an order as ready" << endl;
        }
    }
}
