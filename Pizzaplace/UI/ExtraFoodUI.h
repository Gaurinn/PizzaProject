#ifndef EXTRAFOODUI_H
#define EXTRAFOODUI_H
#include "ExtraFood.h"
#include "ExtraFoodService.h"

class ExtraFoodUI
{
    public:
        ExtraFoodUI();


        void startUI();


        virtual ~ExtraFoodUI();
    protected:
    private:

        ExtraFoodService extrafoodservice;

};

#endif // EXTRAFOODUI_H
