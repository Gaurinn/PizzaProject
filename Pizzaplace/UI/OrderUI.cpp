#include "OrderUI.h"
#include "PizzaUI.h"
#include "OrderService.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <stdio.h>
#define clear() printf("\033[H\033[J")


OrderUI::OrderUI()
{
    //ctor
}



void OrderUI::startUI(){


   clear();//clearing screen

    char selection = '\0';


    clear();//clearing screen
    Order order;
    order.set_is_ready(false);

    cout << "*****************************************" << endl;
    cout << "\t\tNew Order" << endl;
    cout << "*****************************************" << endl;
    cout << endl;

    cout << "Please enter customer name: ";
    string name;
    cin >> name;
    order.set_nameOfCustomer(name);
    cout << endl;

    cout << "Please enter customer phone number: ";
    string number;
    cin >> number;
    order.set_phoneNumberOfCustomer(number);
    cout << endl;

    cout << "Please enter customer address: ";
    string address;
    cin >> address;
    order.set_customerAddress(address);

    clear();
    cout << "Please pick a location for " << order.get_nameOfCustomer() << "'s" <<  " order" << endl;
    cout << endl;

    ///list all locations and pick a location to add to this order

    cout << "Is this order for pick up or delivery" << endl;
    cout << endl;
    cout << "[1]: Pick up" << endl;
    cout << "[2]: Delivery" << endl;
    cout << endl;

    cin >> selection;
    if(selection =='1'){
        cout << "this order is for pick up" << endl;
        order.set_pickup(true);
    }
    else if(selection == '2'){
        cout << "this order is for delivery" << endl;
        order.set_pickup(false);
    }

    cout << "Press 'q' to cancel order, press any other key to continue with order" << endl;
    cin >> selection;

    bool orderComplete = false;
    while(orderComplete == false){

        while(selection != 'q'){
            clear();//clearing screen

            cout << "*****************************************" << endl;
            cout << "  " << order.get_nameOfCustomer() << "'s " << "New Order - Current Price: " << order.get_orderPrice() << endl;
            cout << "*****************************************" << endl;
            cout << endl;

            cout << "[1]: Add Menu Pizza to order" << endl;
            cout << "[2]: Create a Pizza for order" << endl;
            cout << "[3]: Add Extra Food or Drinks to order" << endl;
            cout << "[4]: Add comments or special instructions" << endl;
            cout << "[5]: See current order" << endl;
            cout << "[6]: Complete order" << endl;

            cout << "q: quit" << endl;

            cin >> selection;


            if(selection == '1'){
                clear();//clearing screen
                while(selection != 'c'){
                    clear();//clearing screen
                    cout << "*****************************************" << endl;
                    cout << "\t\t- Pizza Menu -" << endl;
                    cout << "*****************************************" << endl;
                    cout << "[#]: Please pick a number from the menu to add Pizza to order" << endl;
                    cout << endl;
                    cout << "c: cancel" << endl;
                    cout << endl;



                    ///add stuff to list menu pizzas and add to order
                    vector<PizzaMenu> pizzamenu = pizzamenuservice.retrieveAllMenu();
                    for(unsigned int i = 0; i < pizzamenu.size(); i++){
                        cout << "[" << i + 1 << "]" << pizzamenu[i] << endl;
                    }



                    cin >> selection;

                }
            }
            else if(selection == '2'){ ///
                PizzaUI pizzaui;
                pizzaui.startUI();
            }
            else if(selection == '3'){
                clear();//clearing screen
                while(selection != 'c'){
                    cout << "*****************************************" << endl;
                    cout << "\t- Extra Food and Drinks Menu -" << endl;
                    cout << "*****************************************" << endl;
                    cout << "[#]: Please pick a number from the menu to add item to order" << endl;
                    cout << endl;
                    cout << "c: cancel" << endl;


                    vector<ExtraFood> extrafood = extrafoodservice.retrieveAllExtraFoodService(); //get all toppings into a vector
                    for(unsigned int i = 0; i < extrafood.size(); i++){            //print from vector
                        cout << "[" << i + 1 << "]" << extrafood[i] << "kr." << endl;
                    }

                    cin >> selection;
                }
            }
            else if(selection == '4'){
                string comment;
                cout << "Please enter a comment or special instructions for this order:" << endl;
                cin >> comment;
                order.set_comment(comment);
            }
            else if(selection == '5'){

                ///print out entire order with all information

                cout << order.get_nameOfCustomer() << " All the other stuff too" << endl;

            }
            else if(selection == '6'){
                clear();
                            ///print out entire order with all information

                cout << "Would the customer like to pay now or when he receives his order" << endl;
                cout << endl;
                cout << "[1]: Pay now" << endl;
                cout << "[2]: Later" << endl;
                cout << endl;

                cin >> selection;
                if(selection == '1'){
                    order.set_is_paid(true);
                    cout << "Order has been paid for" << endl;
                }
                else if(selection == '2'){
                    order.set_is_paid(false);
                    cout << "Order has not been paid for" << endl;
                }
                cout << "order has been finalized, prepare yourself for the best food of your life" << endl;
                orderComplete = true;
                cout << "Press any key to continue" << endl;
                cin >> selection;
            }

        }
    }
}
