#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include <fstream>
#include "../models/Pizza.h"
#include "InvalidReadException.h"
#include "InvalidWriteException.h"

class PizzaRepository
{
    private:

    public:
        PizzaRepository();
        ~PizzaRepository();
        vector<Pizza> getPizzas();
        void replacePizzasInRepo(vector<Pizza> pizzas);
        void addPizzaToRepo(const Pizza& pizza);
};

#endif // PIZZAREPOSITORY_H
