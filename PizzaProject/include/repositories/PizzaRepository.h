#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include <fstream>
#include "../models/Pizza.h"
class PizzaRepository
{
    private:

    public:
        PizzaRepository();
        ~PizzaRepository();
        vector<Pizza> getPizzas();
        void addPizzaToRepo(Pizza& pizza);
};

#endif // PIZZAREPOSITORY_H
