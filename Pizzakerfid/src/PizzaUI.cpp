
#include "PizzaUI.h"
#include <iostream>

using namespace std;

PizzaUI::PizzaUI()
{
    //ctor
}

PizzaUI::~PizzaUI()
{
    //dtor
}
void PizzaUI::startUIsize() {

    cout << "How large? (in inches)" << endl;

}
void PizzaUI::startUItopping() {
    int topCount;
    cout << "How many toppings: ";
    cin >> topCount;

    Pizza pizza(topCount);

    for (int i = 0; i < topCount; i++) {
        Topping topping;
        cin >> topping;
        pizza.addTopping(topping);
    }
}
