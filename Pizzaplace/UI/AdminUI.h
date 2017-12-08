#ifndef ADMINUI_H
#define ADMINUI_H
#include "../REPO/ToppingRepository.h"
#include "../REPO/PizzaMenuRepository.h"
#include "../REPO/ExtraFoodRepository.h"
#include "../REPO/LocationRepository.h"
#include "../SERVICE/ToppingService.h"


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

};

#endif // ADMINUI_H
