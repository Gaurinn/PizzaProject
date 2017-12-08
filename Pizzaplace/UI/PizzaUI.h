#ifndef PIZZAUI_H
#define PIZZAUI_H
#include "../REPO/PizzaRepository.h"
#include "../REPO/ToppingRepository.h"

class PizzaUI
{
    public:
        PizzaUI();

        void startUI();

    private:
        PizzaRepository pizzaRepo;
        ToppingRepository toppingRepo;
};

#endif // PIZZAUI_H
