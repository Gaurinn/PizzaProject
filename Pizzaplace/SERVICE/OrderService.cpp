#include "OrderService.h"
#include "OrderRepository.h"

OrderService::OrderService()
{
    //ctor
}

void OrderService::createAnOrder(string name, string number){
    Order order(name, number);
    cout << order;
    orderrepo.storeOrder(order);
}


