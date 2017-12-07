#ifndef PIZZAUI_H
#define PIZZAUI_H
#include "../services/PizzaService.h"
#include "../services/ToppingService.h"
#include "ToppingUI.h"
#include "BaseUI.h"

class PizzaUI
{

    private:
        PizzaService pizzaservice;
        ToppingService toppingservice;
        ToppingUI toppingui;
        BaseUI baseui;
    public:
        PizzaUI();
        ~PizzaUI();
        void startUI();
};

#endif // PIZZAUI_H
