#ifndef PIZZAMENUUI_H
#define PIZZAMENUUI_H
#include "PizzaMenuService.h"
#include "ToppingService.h"


class PizzaMenuUI
{
    public:
        PizzaMenuUI();


        void startUI();
        PizzaMenuService pizzamenuservice;
        ToppingService toppingservice;



        virtual ~PizzaMenuUI();
    protected:
    private:
};

#endif // PIZZAMENUUI_H
