#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H
#include "../models/Pizza.h"
#include "../models/Base.h"
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

        int getPriceOfPizza();
        void addBaseToPizza(Base& Base);
        void addToppingToPizza(Topping& topping);
        void addPizza(const Pizza& pizza);
        Pizza getPizza();
        void getPizzaList();
        void listAvailablePizzas();

};

#endif // PIZZASERVICE_H
