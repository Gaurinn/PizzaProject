#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <string.h>
using namespace std;

class Location
{
    public:
        Location();

        Location(string name, int phone);

        void write(ofstream& fout) const;
        void read(ifstream& fin);


        string get_name();
        void set_name(string name);
        double get_phone();
        void set_phone(int phone);



        friend ostream& operator <<(ostream& outs, const Location& location);
        friend istream& operator >>(istream& ins, Location& location);


        virtual ~Location();
    protected:
    private:
        string name;
        int phone;
};

#endif // LOCATION_H
