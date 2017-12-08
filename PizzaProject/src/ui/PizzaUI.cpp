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

    pizzaservice.clearPizzas();

    cout << "Pick base: " << endl;
    baseui.listBases();
    Base base;
    cin >> choiceOfBase;

    base = baseservice.getBaseAt(choiceOfBase - 1);

    //pizzaservice.addBaseToPizza(base);

    cout << endl;

    cout << "How many toppings?" << endl;
    cin >> numberOfToppings;

    cout << "Pick " << numberOfToppings << " toppings from list: " << endl;

    toppingui.listToppings();

    vector<Topping> toppings;
    Topping topping;
    for(int i = 0; i < numberOfToppings; i++){
        cin >> choiceOfTopping;

        topping = toppingservice.getToppingAt(choiceOfTopping - 1);
        toppings.push_back(topping);
        //pizzaservice.addToppingToPizza(topping);
    }

    /*cout << "Price of pizza is: " << pizzaservice.getPriceOfPizza() << endl;*/

    Pizza pizza;

    pizza = pizzaservice.makePizza(base, toppings);

    pizzaservice.addPizza(pizza);

    cout << pizza;
}

void PizzaUI::listAvailablePizzas(){
    cout << "Available pizzas: " << endl;
    pizzaservice.listAvailablePizzas();
}
