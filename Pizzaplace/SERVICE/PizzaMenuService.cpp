#include "PizzaMenuService.h"

PizzaMenuService::PizzaMenuService()
{
    //ctor
}

PizzaMenuService::~PizzaMenuService()
{
    //dtor
}

vector<PizzaMenu> PizzaMenuService::retrieveAllMenu(){

    vector<PizzaMenu> pizzamenu;


    pizzamenurepo.retrieveAllPizzasMenu();


    return pizzamenu;
}
