#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H
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

        Pizza makePizza(const string& name, const Base& base, vector<Topping> toppings);
        void clearPizzas();
        Pizza getPizzaAt(int i);
        int getPriceOfPizza();
        void addBaseToPizza(const Base& Base);
        void addToppingToPizza(Topping& topping);
        void addPizza(const Pizza& pizza);
        Pizza getPizza();
        void getPizzaList();
        vector<Pizza> listAvailablePizzas();
        void replaceAndSavePizzaAt(int i, Pizza& pizza);
        void deletePizzaAtAndSave(int i);

};

#endif // PIZZASERVICE_H
