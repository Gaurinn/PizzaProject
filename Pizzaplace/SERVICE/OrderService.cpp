#include "OrderService.h"

OrderService::OrderService()
{
    //ctor
}

void OrderService::createNewOrder(Order& order, string name, string phonenumber){
    order.set_nameOfCustomer(name);
    order.set_phoneNumberOfCustomer(phonenumber);

}


