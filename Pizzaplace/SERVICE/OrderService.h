#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H
#include "Order.h"
#include "OrderRepository.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class OrderService
{
    public:
        OrderService();

    void createAnOrder(string name, string number);



    private:
        OrderRepository orderrepo;



};

#endif // ORDERSERVICE_H
