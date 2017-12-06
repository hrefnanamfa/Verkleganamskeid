#include "ToppingService.h"

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

void ToppingService::listToppings(){

}
