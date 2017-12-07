#include "../../include/services/PizzaService.h"

PizzaService::PizzaService()
{
    //ctor
}

PizzaService::~PizzaService()
{
    //dtor
}

void PizzaService::addToppingToPizza(Topping& topping){
    pizza.addTopping(topping);
}

void PizzaService::addPizza(Pizza& pizza){
    cout << "Next is adding the pizza to the repo" << endl;
}
