#ifndef SALESUI_H
#define SALESUI_H

#include "PizzaService.h"
#include "OrderService.h"
#include "PizzaUI.h"

class SalesUI
{
    private:
        OrderService orderservice;
        PizzaService pizzaservice;
        PizzaUI pizzaui;

    public:
        SalesUI();
        virtual ~SalesUI();
        void startUI();
        bool checkAnswer(char answer);

};

#endif // SALESUI_H
