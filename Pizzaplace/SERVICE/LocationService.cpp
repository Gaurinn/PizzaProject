#include "LocationService.h"

LocationService::LocationService()
{
    //ctor
}

LocationService::~LocationService()
{
    //dtor
}


vector<Location> LocationService::retrieveAllLocationsService(){

    vector<Location> location = locationrepo.retrieveAllLocations();


    return location;
}


void LocationService::storeLocationService(const Location& location){       ///store pizza to binary file

    locationrepo.storeLocation(location);

}
