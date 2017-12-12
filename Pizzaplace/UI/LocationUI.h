#ifndef LOCATIONUI_H
#define LOCATIONUI_H
#include "LocationService.h"


class LocationUI
{
    public:
        LocationUI();
        virtual ~LocationUI();

        void startUI();


    protected:
    private:

    LocationService locationservice;
};

#endif // LOCATIONUI_H
