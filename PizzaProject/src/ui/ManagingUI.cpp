#include "ManagingUI.h"

ManagingUI::ManagingUI()
{
    //ctor
}

ManagingUI::~ManagingUI()
{
    //dtor
}
void ManagingUI::startUI(){
    char selection = '\n';
    while (selection != 'Q'){
        cout << "1. Register a price for a base pizza" << endl;
        cout << "2. Register toppings and price for each topping" << endl;
        cout << "3. List toppings and bases with price" << endl;
        cout << "4. Register an ordered pizza (and show price)" << endl;
        cout << "5. List pizzas made" << endl;
        cout << "q. to go back" << endl;

        cin >> selection;

        selection = toupper(selection);

        PizzaUI pizzaui;

        if(selection == '1'){
            baseui.createBase();
        }
        else if(selection == '2'){
            toppingui.createToppings();
        }
        else if(selection == '3'){
            baseui.listBases();
            cout << endl;
            toppingui.listToppings();
            cout << endl;
        }
        else if(selection == '4'){
            pizzaui.startUI();
        }
        else if(selection == '5'){
            pizzaui.listAvailablePizzas();
        }
        else if(selection == '6'){

        }

    }
}
