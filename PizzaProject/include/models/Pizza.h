#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include "Topping.h"
#include "Base.h"
#include <vector>

using namespace std;

class Pizza
{
    private:
        double price;
        Base base;
        vector<Topping> toppings;

    public:
        Pizza();
        virtual ~Pizza();
        void addTopping(Topping topping);
        void setBase(Base base);
        void setPrice(double price);
        void write(ofstream& fout) const;
        void read(ifstream& fin);
        friend istream& operator >> (istream& in, Pizza& pizza);
        friend ostream& operator << (ostream& out, Pizza& pizza);

};


#endif // PIZZA_H
