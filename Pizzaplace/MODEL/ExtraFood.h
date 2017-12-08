#ifndef EXTRAFOOD_H
#define EXTRAFOOD_H
#include <iostream>
#include <string.h>
using namespace std;

class ExtraFood
{
    public:
        ExtraFood();

        ExtraFood(string name, double price);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend ostream& operator <<(ostream& outs, const ExtraFood& extrafood);
        friend istream& operator >>(istream& ins, ExtraFood& extrafood);

        virtual ~ExtraFood();
    protected:
    private:
        string name;
        double price;
};

#endif // EXTRAFOOD_H
