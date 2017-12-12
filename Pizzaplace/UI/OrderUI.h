#ifndef ORDERUI_H
#define ORDERUI_H
#include "Order.h"
#include "OrderService.h"
#include "PizzaMenu.h"
#include "PizzaMenuService.h"
#include "ExtraFoodRepository.h"
#include "ExtraFoodService.h"

class OrderUI
{
    public:
        OrderUI();


        void startUI();

    private:

        PizzaMenuService pizzamenuservice;
        OrderService orderservice;
        ExtraFoodService extrafoodservice;
        ExtraFoodRepository extrafoodrepo;
};

#endif // ORDERUI_H
