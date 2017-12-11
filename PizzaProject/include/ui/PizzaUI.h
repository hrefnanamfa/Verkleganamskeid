#ifndef PIZZAUI_H
#define PIZZAUI_H
#include "../services/PizzaService.h"
#include "../services/ToppingService.h"
#include "ToppingUI.h"
#include "BaseUI.h"
#include "PizzaUI.h"

class PizzaUI
{

    private:
        PizzaService pizzaservice;
        ToppingService toppingservice;
        BaseService baseservice;
        ToppingUI toppingui;
        BaseUI baseui;
    public:
        PizzaUI();
        ~PizzaUI();
        Pizza makeAPizza();
        void startUIpizzamenu();
        void listAvailablePizzas();
};

#endif // PIZZAUI_H