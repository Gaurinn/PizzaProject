#ifndef TOPPINGREPOSITORY_H
#define TOPPINGREPOSITORY_H
#include "../MODEL/Topping.h"
#include <vector>
using namespace std;

class ToppingRepository
{
    public:
        ToppingRepository();
        virtual ~ToppingRepository();


        void storeTopping(const Topping& topping);
        Topping retrieveTopping();

        vector<Topping> retrieveAllToppings();

    protected:
    private:
};

#endif // TOPPINGREPOSITORY_H
