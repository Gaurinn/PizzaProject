#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H
#include "../REPO/ToppingRepository.h"
#include "../REPO/PizzaMenuRepository.h"
#include "../REPO/ExtraFoodRepository.h"
#include "../REPO/LocationRepository.h"

class ToppingService
{
    public:
        ToppingService();

        ToppingRepository get_toppingrepo();
        void set_toppingrepo(ToppingRepository toppingrepo);
        void storeTopping(Topping topping);

        vector<Topping> retrieveAllToppingsService();



        virtual ~ToppingService();
    protected:
    private:

        ToppingRepository toppingrepo;
       /* PizzaMenuRepository pizzaMenuRepo;
        ExtraFoodRepository extraFoodRepo;
        LocationRepository locationRepo;*/

};

#endif // TOPPINGSERVICE_H
