#ifndef SALESUI_H
#define SALESUI_H

#include "../services/PizzaService.h"
#include "../services/OrderService.h"
#include "PizzaUI.h"
#include "Extrasui.h"
#include "../services/ExtrasService.h"

class SalesUI
{
    private:
        OrderService orderservice;
        PizzaService pizzaservice;
        PizzaUI pizzaui;
        ExtrasUI extrasui;
        ExtrasService extrasservice;

    public:
        SalesUI();
        virtual ~SalesUI();
        void startUI();
        bool checkAnswer(char answer);

};

#endif // SALESUI_H
