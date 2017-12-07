#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H
#include "../models/Pizza.h"
#include "../repositories/PizzaRepository.h"

class PizzaService
{

    private:
        PizzaRepository pizzarepo;

    public:
        PizzaService();
        ~PizzaService();
        void addPizza(Pizza& pizza);

};

#endif // PIZZASERVICE_H
