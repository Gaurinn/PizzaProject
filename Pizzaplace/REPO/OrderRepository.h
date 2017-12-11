#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H
#include "Order.h"

using namespace std;

class Order;
class OrderRepository
{
    public:
        OrderRepository();

        void storeOrder(const Order& order);



    private:


};

#endif // ORDERREPOSITORY_H
