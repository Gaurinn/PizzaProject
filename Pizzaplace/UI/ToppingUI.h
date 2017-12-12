#ifndef TOPPINGUI_H
#define TOPPINGUI_H
#include "ToppingService.h"


class ToppingUI
{
    public:
        ToppingUI();


        void startUI();
        ToppingService toppingservice;


        virtual ~ToppingUI();
    protected:
    private:
};

#endif // TOPPINGUI_H
