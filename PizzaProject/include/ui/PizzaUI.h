#ifndef PIZZAUI_H
#define PIZZAUI_H
#include "PizzaService.h"

class PizzaUI
{

    private:
        PizzaService pizzaservice;
    public:
        PizzaUI();
        ~PizzaUI();
        void startUI();
};

#endif // PIZZAUI_H
