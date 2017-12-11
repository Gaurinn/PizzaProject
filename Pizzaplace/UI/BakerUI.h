#ifndef BAKERUI_H
#define BAKERUI_H
#include "LocationRepository.h"

class BakerUI
{
    public:
        BakerUI();
        void startUI();
    private:
        LocationRepository locationRepo;

};

#endif // BAKERUI_H
