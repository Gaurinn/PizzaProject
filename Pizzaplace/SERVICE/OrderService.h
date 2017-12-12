#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H
#include "Order.h"


class OrderService
{
    public:
        OrderService();

        void createNewOrder(Order& order, string name, string phonenumber);

        vector<ExtraFood> retrieveAllExtraFood();


    private:

};

#endif // ORDERSERVICE_H
