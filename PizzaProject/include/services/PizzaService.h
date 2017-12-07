#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H
#include "../models/Pizza.h"
#include "../repositories/PizzaRepository.h"
#include "../../include/models/Topping.h"

class PizzaService
{

    private:
        PizzaRepository pizzarepo;
        Pizza pizza;

    public:
        PizzaService();
        ~PizzaService();
        void addToppingToPizza(Topping& topping);
        void addPizza(Pizza& pizza);

};

#endif // PIZZASERVICE_H
