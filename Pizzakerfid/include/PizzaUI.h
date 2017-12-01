#ifndef PIZZAUI_H
#define PIZZAUI_H
#include "Pizza.h"



class PizzaUI
{
    private:
        Pizza pizza;
    public:
        PizzaUI();
        virtual ~PizzaUI();

        void startUIsize();
        void startUItopping();
};

#endif // PIZZAUI_H
