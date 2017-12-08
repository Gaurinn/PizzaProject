#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include <vector>
#include "../MODEL/Pizza.h"



class PizzaRepository
{
    public:
        PizzaRepository();
        virtual ~PizzaRepository();

        void storePizza(const Pizza& pizza);
        Pizza retrievePizza();

        vector<Pizza> retrieveAllPizzas();



    protected:
    private:
};

#endif // PIZZAREPOSITORY_H
