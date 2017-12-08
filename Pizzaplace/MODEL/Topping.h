#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>
#include <string.h>
using namespace std;

class Topping
{
    public:
        Topping();

        Topping(string name, double price);

        void write(ofstream& fout) const;
        void read(ifstream& fin);


        string get_name();
        double get_price();

        friend ostream& operator <<(ostream& outs, const Topping& topping);
        friend istream& operator >>(istream& ins, Topping& topping);

        virtual ~Topping();
    protected:
    private:
        string name;
        double price;
};

#endif // TOPPING_H
