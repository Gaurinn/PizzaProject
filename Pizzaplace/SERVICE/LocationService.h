#ifndef LOCATIONSERVICE_H
#define LOCATIONSERVICE_H
#include "LocationRepository.h"


class LocationService
{
    public:
        LocationService();




        vector<Location> retrieveAllLocationsService();
        void storeLocationService(const Location& location);



        virtual ~LocationService();
    protected:
    private:






        LocationRepository locationrepo;
};

#endif // LOCATIONSERVICE_H
