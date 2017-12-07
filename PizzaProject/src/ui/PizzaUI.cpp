#include "../../include/ui/PizzaUI.h"

PizzaUI::PizzaUI()
{
    //ctor
}

PizzaUI::~PizzaUI()
{
    //dtor
}
void PizzaUI::startUI(){
	int numberOfToppings = 0;
    int choiceOfTopping = 0;

    cout << "Making pizza order" << endl;

    cout << "Pick base: ";

    cout << endl;

    cout << "How many toppings?" << endl;
    cin >> numberOfToppings;

    cout << "Pick " << numberOfToppings << " toppings from list: " << endl;

    toppingui.listToppings();

    Topping topping;

    for(int i = 0; i < numberOfToppings; i++){
        cin >> choiceOfTopping;
        topping = toppingservice.getToppingAt(choiceOfTopping - 1);
        pizzaservice.addToppingToPizza(topping);
    }
}
