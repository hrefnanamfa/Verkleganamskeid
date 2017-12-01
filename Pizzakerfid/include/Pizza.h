#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include "Topping.h"
#include "Size.h"
#include "PizzaType.h"

using namespace std;

class Pizza
{
    private:
        Size size;
        PizzaType pizzatype;
        Topping *toppings;
        int toppingCount;
        int currentToppingNum;

    public:
        Pizza();
        virtual ~Pizza();
        Pizza(int numberOfToppings);
        int getToppingCount()const;
        void initialize(int numberOfToppings, int inches);
        void setSize(int number, int inches);
        void addTopping(Topping topping);
        friend ostream& operator <<(ostream& out, const Pizza& pizza);
        friend istream& operator >>(istream& in, Pizza& pizza);
};

#endif // PIZZA_H
