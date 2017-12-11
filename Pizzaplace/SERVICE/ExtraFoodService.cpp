#include "ExtraFoodService.h"

ExtraFoodService::ExtraFoodService()
{
    //ctor
}

ExtraFoodService::~ExtraFoodService()
{
    //dtor
}


vector<ExtraFood> ExtraFoodService::retrieveAllExtraFood(){

    vector<ExtraFood> extrafood;


    extrafoodrepo.retrieveAllExtraFood();


    return extrafood;
}
