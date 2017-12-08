#include "../../include/services/PizzaService.h"

PizzaService::PizzaService()
{
    //ctor
}

PizzaService::~PizzaService()
{
    //dtor
}
void PizzaService::clearPizzas(){
    pizzas.clear();
}

void PizzaService::addToppingToPizza(Topping& topping){
    pizza.addTopping(topping);
}
int PizzaService::getPriceOfPizza(){
    return pizza.getPriceOfPizza();
}

void PizzaService::addBaseToPizza(const Base& base){
    pizza.setBase(base);
}

Pizza PizzaService::makePizza(const Base& base, const vector<Topping> toppings){
    Pizza pizza;

    pizza.setBase(base);

    pizza.setToppings(toppings);

    return pizza;
}

void PizzaService::addPizza(const Pizza& pizza){
    cout << "Next is adding the pizza to the repo" << endl;
    pizzarepo.addPizzaToRepo(pizza);
}

Pizza PizzaService::getPizza(){
    return pizza;
}

void PizzaService::getPizzaList(){
    pizzas = pizzarepo.getPizzas();
}

void PizzaService::listAvailablePizzas(){
    getPizzaList();
    for(unsigned int i= 0; i < pizzas.size(); i++){
        cout << i + 1 << ". " << pizzas[i] << endl;
    }
}
