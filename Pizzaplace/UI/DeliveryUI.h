#ifndef DELIVERYUI_H
#define DELIVERYUI_H
#include "LocationRepository.h"

class DeliveryUI
{
    public:
        DeliveryUI();


        void startUI();

    private:

        LocationRepository locationRepo;

};

#endif // DELIVERYUI_H
