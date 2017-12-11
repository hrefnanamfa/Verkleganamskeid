#ifndef SALESUI_H
#define SALESUI_H

#include "../services/PizzaService.h"
#include "../services/OrderService.h"
#include "PizzaUI.h"
#include "Extrasui.h"
#include "../services/ExtrasService.h"
#include "WorkplacesUI.h"
#include "../services/WorkplacesService.h"

class SalesUI
{
    private:
        OrderService orderservice;
        PizzaService pizzaservice;
        ExtrasService extrasservice;
        WorkplacesService workplacesservice;
        PizzaUI pizzaui;
        ExtrasUI extrasui;
        WorkplacesUI workplacesui;
        Order order;
        Workplaces workplaces;
        vector<Pizza> pizzasInOrder;
        vector<Extras> extrasInOrder;

    public:
        SalesUI();
        virtual ~SalesUI();
        void startUI();
        bool checkAnswer(char answer);
};

#endif // SALESUI_H
