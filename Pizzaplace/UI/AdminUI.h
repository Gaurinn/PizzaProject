#ifndef ADMINUI_H
#define ADMINUI_H
#include "../REPO/ToppingRepository.h"
#include "../REPO/PizzaMenuRepository.h"
#include "../REPO/ExtraFoodRepository.h"
#include "../REPO/LocationRepository.h"
#include "../SERVICE/ToppingService.h"
#include "PizzaMenuService.h"
#include "ExtraFoodService.h"
#include "LocationService.h"
#include "ToppingUI.h"
#include "PizzaMenuUI.h"
#include "ExtraFoodUI.h"
#include "LocationUI.h"


class AdminUI
{
    public:
        AdminUI();

        void startUI();


    private:
        ToppingService toppingservice;
        ToppingRepository toppingRepo;

        PizzaMenuRepository pizzaMenuRepo;
        ExtraFoodRepository extrafoodrepo;

        LocationRepository locationRepo;
        LocationService locationservice;


        PizzaMenuService pizzaMenuService;
        ExtraFoodService extrafoodservice;

        ToppingUI toppingui;
        PizzaMenuUI pizzamenuui;
        ExtraFoodUI extrafoodui;
        LocationUI locationui;

};

#endif // ADMINUI_H
