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
        bool verbose;
    public:
        PizzaUI();
        ~PizzaUI();
        Pizza makeAPizza();
        bool isPizzaVectorEmpty();
        void startUI();
        void startUIpizzamenu();
        void listAvailablePizzas();
<<<<<<< HEAD
        int getPizzaMenuSize();
=======
        void setVerbose(bool verbose);
        bool isVerbose();
>>>>>>> 74f0213d20e458bc90773fbdc5b03a0df6d9f440
};

#endif // PIZZAUI_H
