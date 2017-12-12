#include "ExtraFoodService.h"

ExtraFoodService::ExtraFoodService()
{
    //ctor
}

ExtraFoodService::~ExtraFoodService()
{
    //dtor
}


vector<ExtraFood> ExtraFoodService::retrieveAllExtraFoodService(){

    vector<ExtraFood> extrafoods = extrafoodrepo.retrieveAllExtraFood();


    //cout << extrafoods[0].get_name() << endl;
    return extrafoods;
}

void ExtraFoodService::storeExtraFoodService(const ExtraFood& extrafood){       ///store pizza to binary file

    extrafoodrepo.storeExtraFood(extrafood);

}
