#include "ToppingService.h"

ToppingService::ToppingService()
{
    //ctor
}

ToppingService::~ToppingService()
{
    //dtor
}

ToppingRepository ToppingService::get_toppingrepo(){


    return toppingrepo;
}


vector<Topping> ToppingService::retrieveAllToppingsService(){

    vector<Topping> toppings = toppingrepo.retrieveAllToppings();


    //cout << extrafoods[0].get_name() << endl;
    return toppings;
}


void ToppingService::set_toppingrepo(ToppingRepository toppingrepo){

    this->toppingrepo = toppingrepo;
}

void ToppingService::storeTopping(Topping topping){

    toppingrepo.storeTopping(topping);

}
