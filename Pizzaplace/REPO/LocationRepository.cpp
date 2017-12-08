#include "LocationRepository.h"
#include <fstream>

LocationRepository::LocationRepository()
{
    //ctor
}

LocationRepository::~LocationRepository()
{
    //dtor
}

void LocationRepository::storeLocation(const Location& location){ ///store Location to binary file
    ofstream fout;
    fout.open("locationsBinary.bin", ios::binary|ios::app);
    location.write(fout);
    fout.close();
}

Location LocationRepository::retrieveLocation(){ ///read Location from binary file
    ifstream fin;
    fin.open("locationssBinary.bin", ios::binary);
    Location location;
    location.read(fin);
    fin.close();
    return location;
}

vector<Location> LocationRepository::retrieveAllLocations(){  ///read all locations from binary file
    vector<Location> locations;
    ifstream fin;
    fin.open("locationsBinary.bin", ios::binary);
    Location location;
    while(true){
        int filePos = fin.tellg();          //current position in file
        fin.seekg(0, fin.end);              //go to end
        int endPos = fin.tellg();           //end position in file
        if((endPos - filePos) <= 1){        //if true last record read... not enough space left for whole record
            break;
        }
        fin.seekg(filePos);
        location.read(fin);
        locations.push_back(location);
    }
    fin.close();
    return locations;
}
