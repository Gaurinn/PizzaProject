#ifndef PIZZAMENUSERVICE_H
#define PIZZAMENUSERVICE_H
#include <vector>
#include "PizzaMenu.h"
#include "PizzaMenuRepository.h"


class PizzaMenuService
{
    public:
        PizzaMenuService();
        virtual ~PizzaMenuService();

        vector<PizzaMenu> retrieveAllMenu();
        void storePizzaMenuService(const PizzaMenu& pizzamenu);

    protected:
    private:


        PizzaMenuRepository pizzamenurepo;
};

#endif // PIZZAMENUSERVICE_H
