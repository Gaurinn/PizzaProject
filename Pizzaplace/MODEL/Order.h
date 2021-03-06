#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <iostream>
#include <vector>
#include "Pizza.h"
#include "ExtraFood.h"
#include "PizzaMenu.h"

using namespace std;


class Order
{
    public:
        Order();
        Order(string nameOfCustomer,string phoneNumberOfCustomer);

        double get_orderPrice();
        string get_nameOfCustomer();
        string get_phoneNumberOfCustomer();
        bool get_pickup();
        string get_addressOfCustomer();
        char get_status();
        bool get_paid();
        string get_comment();


        void set_customerAddress(string address);
        void set_is_ready(bool is_ready);
        void set_is_paid(bool is_paid);
        void set_nameOfCustomer(string nameOfCustomer);
        void set_phoneNumberOfCustomer(string phoneNumberOfCustomer);
        void set_orderPrice(double orderprice);
        void set_pickup(bool pickup);
        void set_status(char status);
        void set_paid(bool paid);
        void set_comment(string comment);

        friend ostream& operator <<(ostream& outs, const Order& order);

    private:

        string address;
        bool is_ready;
        bool is_paid;
        string nameOfCustomer;          /// the name of the customer
        string phoneNumberOfCustomer;   /// the phone number of the customer
        bool pickup;                    /// true: the order will be picked up, false: the order will be delivered to "addressOfCustomer"
        string addressOfCustomer;       /// the address of customer, if order is delivered
        double orderPrice;              /// total price of the order
        char status;                    /// n: new, p: in progress, r: ready, d: delivered
        bool paid;                      /// has the order been paid for, true / false
        string comment;                 /// users can comment on an order and read comments
        string location;                /// where is the pizza supposed to be baked

        vector<Pizza> pizza;
        vector<PizzaMenu> pizzamenu;
        vector<ExtraFood> extrafood;
};

#endif // ORDER_H
