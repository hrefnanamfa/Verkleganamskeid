#ifndef PIZZAUI_H
#define PIZZAUI_H
#include "../services/PizzaService.h"
#include "../services/ToppingService.h"
#include "ToppingUI.h"
#include "BaseUI.h"
#include "PizzaUI.h"
#include "InvalidPizzaException.h"

class PizzaUI
{

    private:
        PizzaService pizzaservice;
        ToppingService toppingservice;
        BaseService baseservice;
        ToppingUI toppingui;
        BaseUI baseui;
        vector<Pizza> pizzas;
    public:
        PizzaUI();
        ~PizzaUI();
        Pizza makeAPizza();
        bool isPizzaVectorEmpty();
        void startUI();
        void startUIpizzamenu();
        void listAvailablePizzas();
        int getPizzaMenuSize();
};

#endif // PIZZAUI_H
