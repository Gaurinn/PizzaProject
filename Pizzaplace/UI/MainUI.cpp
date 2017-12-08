#include "MainUI.h"
#include "AdminUI.h"
#include "SalesUI.h"
#include "BakerUI.h"
#include "DeliveryUI.h"
#include <stdlib.h>
#include <stdio.h>
#define clear() printf("\033[H\033[J")

MainUI::MainUI()
{
    //ctor
}

void MainUI::startUI(){

    char selection = '\0';

    while(selection != 'q'){
        clear();
        cout << "*****************************************" << endl;
        cout << "*\ta: Log in as Admin\t\t*" << endl;
        cout << "*\ts: Log in as Sales staff\t*" << endl;
        cout << "*\tb: log in as Baker staff\t*" << endl;
        cout << "*\td: log in as Delivery staff\t*" << endl;
        cout << "*\tq: quit\t\t\t\t*" << endl;
        cout << "*****************************************" << endl;

        AdminUI adminui;
        SalesUI salesui;
        BakerUI bakerui;
        DeliveryUI deliveryui;

        cin >> selection;

        switch(selection){
        case 'a':
            adminui.startUI();
            break;
        case 's':
            salesui.startUI();
            break;
        case 'b':
            bakerui.startUI();
            break;
        case 'd':
            deliveryui.startUI();
            break;
        }
    }
}
