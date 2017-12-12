#include "Order.h"

Order::Order()
{
    //ctor
}

Order::Order(string nameOfCustomer,string phoneNumberOfCustomer){
    this -> nameOfCustomer = nameOfCustomer;
    this -> phoneNumberOfCustomer = phoneNumberOfCustomer;
    this -> pickup = true;
    this -> addressOfCustomer = "";
    this -> orderPrice = 0;
    this -> status = '\0';
    this -> paid = false;
    this -> comment = "";
    this -> location = "";
}



double Order::get_orderPrice(){
    return orderPrice;
}
string Order::get_nameOfCustomer(){
    return nameOfCustomer;
}
string Order::get_phoneNumberOfCustomer(){
    return phoneNumberOfCustomer;
}
bool Order::get_pickup(){
    return pickup;
}
string Order::get_addressOfCustomer(){
    return addressOfCustomer;
}
char Order::get_status(){
    return status;
}
bool Order::get_paid(){
    return paid;
}
string Order::get_comment(){
    return comment;
}

void Order::set_customerAddress(string address){
    this->address = address;
}

void Order::set_is_ready(bool is_ready){
    this->is_ready = is_ready;
}

void Order::set_is_paid(bool is_paid){
    this->is_paid = is_paid;
}
void Order::set_nameOfCustomer(string nameOfCustomer){
    this->nameOfCustomer = nameOfCustomer;
}

void Order::set_phoneNumberOfCustomer(string phoneNumberOfCustomer){
    this->phoneNumberOfCustomer = phoneNumberOfCustomer;
}

void Order::set_orderPrice(double orderPrice){
    this->orderPrice = orderPrice;
}

void Order::set_pickup(bool pickup){
    this->pickup = pickup;
}
void Order::set_status(char status){
    this->status = status;
}
void Order::set_paid(bool paid){
    this->paid = paid;
}
void Order::set_comment(string comment){
    this->comment = comment;
}


ostream& operator <<(ostream& outs, const Order& order){
    outs << order.nameOfCustomer << "," << order.phoneNumberOfCustomer << "," << order.pickup << "," <<
    order.addressOfCustomer << "," << order.orderPrice << "," << order.status << "," << order.paid << "," << order.comment << "," <<
    order.location << ",";

    return outs;
}


