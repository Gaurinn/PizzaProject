#ifndef PIZZAMENUREPOSITORY_H
#define PIZZAMENUREPOSITORY_H
#include <vector>
#include "../MODEL/PizzaMenu.h"



class PizzaMenuRepository
{
    public:
        PizzaMenuRepository();
        virtual ~PizzaMenuRepository();

        void storePizzaMenu(const PizzaMenu& pizzamenu);
        PizzaMenu retrievePizzaMenu();

        vector<PizzaMenu> retrieveAllPizzasMenu();


    protected:
    private:
};

#endif // PIZZAREPOSITORY_H
