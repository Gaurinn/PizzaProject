#ifndef ADMINUI_H
#define ADMINUI_H
#include "../REPO/ToppingRepository.h"
#include "../REPO/PizzaMenuRepository.h"
#include "../REPO/ExtraFoodRepository.h"
#include "../REPO/LocationRepository.h"
#include "../SERVICE/ToppingService.h"
#include "PizzaMenuService.h"


class AdminUI
{
    public:
        AdminUI();

        void startUI();


    private:
        ToppingService toppingservice;
        ToppingRepository toppingRepo;
        PizzaMenuRepository pizzaMenuRepo;
        ExtraFoodRepository extraFoodRepo;
        LocationRepository locationRepo;

        PizzaMenuService pizzaMenuService;


};

#endif // ADMINUI_H
