#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"
#include "Base.h"
#include <iostream>
#include <vector>

using namespace std;

class Pizza
{
    private:
        string name;
        int price;
        Base base;
        vector<Topping> toppings;

    public:
        Pizza();
        void setName(string name);
        string getName();
        void setToppings(vector<Topping> toppings);
        int getPriceOfPizza();
        void addTopping(const Topping& topping);
        void setBase(const Base& base);
        void setPrice(int price);
        void write(ofstream& fout) const;
        void read(ifstream& fin);
        friend istream& operator >> (istream& in, Pizza& pizza);
        friend ostream& operator << (ostream& out, Pizza& pizza);

};

#endif // PIZZA_H
