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
    int choiceOfBase = 0;

    cout << "Making pizza order" << endl;

    cout << "Pick base: " << endl;
    baseui.listBases();
    Base base;
    cin >> choiceOfBase;
    base = baseservice.getBaseAt(choiceOfBase - 1);
    pizzaservice.addBaseToPizza(base);

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

    cout << "Price of pizza is: " << pizzaservice.getPriceOfPizza() << endl;
    Pizza pizza;
    pizza = pizzaservice.getPizza();

    pizzaservice.addPizza(pizza);
}

void PizzaUI::listAvailablePizzas(){
    cout << "" << endl;
    pizzaservice.listAvailablePizzas();
}
