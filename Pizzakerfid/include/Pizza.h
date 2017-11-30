#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include "Topping.h"

using namespace std;

class Pizza
{
    private:
        int size;
        string type;
        Topping *toppings;
        int toppingCount;
        int currentToppingNum;

    public:
        Pizza();
        Pizza(int numberOfToppings);
        int getToppingCount()const;
        virtual ~Pizza();
        void addTopping(Topping topping);
        friend ostream& operator <<(ostream& out, const Pizza& pizza);
        friend istream& operator >>(istream& in, Pizza& pizza);
};

#endif // PIZZA_H
