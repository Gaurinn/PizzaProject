#include "LocationService.h"

LocationService::LocationService()
{
    //ctor
}

LocationService::~LocationService()
{
    //dtor
}


vector<Location> LocationService::retrieveAllLocations(){

    vector<Location> location;


    locationrepo.retrieveAllLocations();


    return location;
}
