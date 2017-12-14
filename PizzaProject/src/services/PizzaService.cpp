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

Pizza PizzaService::makePizza(const string& name, const Base& base, const vector<Topping> toppings){
    Pizza pizza;
    int price = 0;

    pizza.setName(name);

    pizza.setBase(base);

    pizza.setToppings(toppings);

    price = pizza.getPriceOfPizza();
    pizza.setPrice(price);

    return pizza;
}

void PizzaService::addPizza(const Pizza& pizza){
    pizzarepo.addPizzaToRepo(pizza);
}

Pizza PizzaService::getPizza(){
    return pizza;
}

Pizza PizzaService::getPizzaAt(int i){
    getPizzaList();
    return pizzas.at(i);
}

void PizzaService::getPizzaList(){
    pizzas = pizzarepo.getPizzas();
}

vector<Pizza> PizzaService::listAvailablePizzas(){
    getPizzaList();
    return pizzas;
}
void PizzaService::replaceAndSavePizzaAt(int i, Pizza& pizza){
    getPizzaList();
    pizzas.at(i) = pizza;
    pizzarepo.replacePizzasInRepo(this->pizzas);
}
void PizzaService::deletePizzaAtAndSave(int i){
    getPizzaList();
    pizzas.erase(pizzas.begin() + i);
    pizzarepo.replacePizzasInRepo(this->pizzas);
}
