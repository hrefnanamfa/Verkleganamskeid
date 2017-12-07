#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H
#include "../models/Pizza.h"
#include "Base.h"
#include "../../include/models/Topping.h"
#include "../repositories/PizzaRepository.h"


class PizzaService
{

    private:
        PizzaRepository pizzarepo;
        Pizza pizza;
        vector<Pizza> pizzas;

    public:
        PizzaService();
        ~PizzaService();

        double getPriceOfPizza();
        void addBaseToPizza(Base& Base);
        void addToppingToPizza(Topping& topping);
        void addPizza(Pizza& pizza);
        Pizza getPizza();
        void getPizzaList();

        void listAvailablePizzas();

};

#endif // PIZZASERVICE_H
