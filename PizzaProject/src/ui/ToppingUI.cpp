#include "ToppingUI.h"

ToppingUI::ToppingUI()
{
    //ctor
}

ToppingUI::~ToppingUI()
{
    //dtor
}

void ToppingUI::createToppings(){
    Topping topping;
    cout << "Making topping" << endl;
    cin >> topping;

    toppingservice.addTopping(topping);
}
