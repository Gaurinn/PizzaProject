#ifndef PIZZAMENU_H
#define PIZZAMENU_H
#include "Topping.h"
#include <iostream>
#include <vector>
class PizzaMenu
{
    public:
        PizzaMenu();

        PizzaMenu(string name, char size, double price);

        void addTopping(Topping topping);


        friend ostream& operator <<(ostream& outs, const PizzaMenu& pizzamenu);
        friend istream& operator >>(istream& ins, PizzaMenu& pizzamenu);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        string get_name();
        void set_name(string name);
        double get_price();
        void set_price(double price);



        virtual ~PizzaMenu();
    protected:
    private:

        vector<Topping> toppings;

        string name; //name of pizza on menu
        char size;
        double price;

};

#endif // PIZZA_H
