#ifndef PIZZAUI_H
#define PIZZAUI_H
#include "../services/PizzaService.h"
#include "../services/ToppingService.h"
#include "ToppingUI.h"
#include "BaseUI.h"
#include "PizzaUI.h"
#include "../exceptions/InvalidPizzaException.h"

#include <sstream>

class PizzaUI
{
    private:
        PizzaService pizzaservice;
        ToppingService toppingservice;
        BaseService baseservice;
        ToppingUI toppingui;
        BaseUI baseui;
        vector<Pizza> pizzas;
        bool verbose;

    public:
        Pizza makeAPizza();
        bool isPizzaVectorEmpty();
        void startUI();
        void startUIpizzamenu();
        void listAvailablePizzas();
        int getPizzaMenuSize();
        void setVerbose(bool verbose);
        bool isVerbose();
};

#endif // PIZZAUI_H
