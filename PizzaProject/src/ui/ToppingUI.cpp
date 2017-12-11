#include "../../include/ui/ToppingUI.h"

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

    cin >> topping;

    toppingservice.addTopping(topping);
}
void ToppingUI::listToppings(){
    cout << "- Toppings -" << endl;
    toppingservice.listAvailableToppings();
}
