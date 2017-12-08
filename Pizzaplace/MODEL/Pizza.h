#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"
#include <iostream>
#include <vector>
class Pizza
{
    public:
        Pizza();

        void addTopping(Topping topping);


        friend ostream& operator <<(ostream& outs, const Pizza& pizza);
        friend istream& operator >>(istream& ins, Pizza& pizza);

        void write(ofstream& fout) const;
        void read(ifstream& fin);




        virtual ~Pizza();
    protected:
    private:

        vector<Topping> toppings;

};

#endif // PIZZA_H
