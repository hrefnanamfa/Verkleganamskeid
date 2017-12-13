#include "../../include/services/ToppingService.h"

ToppingService::ToppingService()
{
    //ctor
}

ToppingService::~ToppingService()
{
    //dtor
}

Topping ToppingService::getToppingAt(int i){
    getToppings();
    return toppings.at(i);
}

void ToppingService::addTopping(Topping& topping){
    toppingrepository.addTopping(topping);
}

void ToppingService::getToppings(){
    toppings = toppingrepository.getToppings();
}

vector <Topping> ToppingService::getToppingVector(){
    return toppings;
}

vector<Topping> ToppingService::listAvailableToppings(){
    getToppings();
    return toppings;
}
void ToppingService::replaceAndSaveToppingAt(int i, Topping& topping){
    getToppings();
    toppings.at(i) = topping;
    toppingrepository.replaceToppingsInRepo(toppings);
}
void ToppingService::deleteToppingAtAndSave(int i){
    getToppings();
    toppings.erase(toppings.begin() + i);
    toppingrepository.replaceToppingsInRepo(toppings);
}
