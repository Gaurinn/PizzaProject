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


    return toppingRepo;
}

void ToppingService::set_toppingrepo(ToppingRepository toppingrepo){

    this->toppingRepo = toppingrepo;
}

void ToppingService::storeTopping(Topping topping){

    toppingRepo.storeTopping(topping);

}
