#ifndef LOCATIONREPOSITORY_H
#define LOCATIONREPOSITORY_H
#include "../MODEL/Location.h"
#include <vector>
using namespace std;

class LocationRepository
{
    public:
        LocationRepository();
        virtual ~LocationRepository();

        void storeLocation(const Location& location);
        Location retrieveLocation();
        vector<Location> retrieveAllLocations();

    protected:
    private:
};

#endif // LOCATIONREPOSITORY_H
