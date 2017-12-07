#include "../../include/services/ToppingService.h"

ToppingService::ToppingService()
{
    //ctor
}

ToppingService::~ToppingService()
{
    //dtor
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

void ToppingService::listAvailableToppings(){
    getToppings();
    for(unsigned int i = 0; i < toppings.size(); i++){
        cout << i + 1  << ". " << toppings[i] << endl;
    }
}
