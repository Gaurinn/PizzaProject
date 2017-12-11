#ifndef LOCATIONSERVICE_H
#define LOCATIONSERVICE_H
#include "LocationRepository.h"


class LocationService
{
    public:
        LocationService();
        virtual ~LocationService();
    protected:
    private:



        vector<Location> retrieveAllLocations();


        LocationRepository locationrepo;
};

#endif // LOCATIONSERVICE_H
