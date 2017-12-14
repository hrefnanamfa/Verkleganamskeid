#ifndef SALESUI_H
#define SALESUI_H

#include "../services/PizzaService.h"
#include "../services/OrderService.h"
#include "PizzaUI.h"
#include "Extrasui.h"
#include "../services/ExtrasService.h"
#include "WorkplacesUI.h"
#include "../services/WorkplacesService.h"

#include "InvalidAnswerException.h"

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
        bool pickup;
        string address;
        int addressNumber;

    public:
        SalesUI();
        virtual ~SalesUI();
        void startUI();
        Order createNewOrder(Order *order);
        bool checkAnswer(char answer);
        void addPizzaFromMenu();
        void setPickupOrDelivery();
        void addExtras();
        void addPizza();
        string getComment();
        void saveOrder(Workplaces workplace, string comment);
};

#endif // SALESUI_H
