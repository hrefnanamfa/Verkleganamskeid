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
    char selection = '\n';
    while (selection != 'Q'){
        cout << "1. Add a pizza to menu" << endl;
        cout << "2. Edit a pizza" << endl;
        cout << "3. Delete a pizza" << endl;
        cout << "4. View menu" << endl << endl;
        cout << "q. to go back" << endl;

        cin >> selection;
        selection = toupper(selection);
        if (selection == '1'){
            startUIpizzamenu();
        }
        else if (selection == '2'){
            int select = 0;
            listAvailablePizzas();
            if(!pizzas.empty()){
                cout << "Select a pizza to edit" << endl;
                cin >> select;
                Pizza pizza;
                pizza = makeAPizza();
                pizzaservice.replaceAndSavePizzaAt(select - 1, pizza);
            }
        }
        else if (selection == '3'){
            int select = 0;
            listAvailablePizzas();
            if(!pizzas.empty()){
                cout << "Select a pizza to delete" << endl;
                cin >> select;
                pizzaservice.deletePizzaAtAndSave(select);
            }

        }
        else if (selection == '4'){
            listAvailablePizzas();
        }
        cout << endl;
    }
}

Pizza PizzaUI::makeAPizza(){
    int numberOfToppings = 0;
    int choiceOfTopping = 0;
    int choiceOfBase = 0;

    pizzaservice.clearPizzas();

    cout << "Pick base: " << endl;
    baseui.listBases();
    Base base;
    cin >> choiceOfBase;

    base = baseservice.getBaseAt(choiceOfBase - 1);
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
    }

    Pizza pizza;
    pizza = pizzaservice.makePizza(base, toppings);

    return pizza;
}

void PizzaUI::startUIpizzamenu(){
    Pizza pizza;
    pizza = makeAPizza();
    pizzaservice.addPizza(pizza);

    cout << "You just registered: " << endl;
    cout << pizza << endl;
}
void PizzaUI::listAvailablePizzas(){
    pizzas = pizzaservice.listAvailablePizzas();
    if(!pizzas.empty()){
        cout << "- Available pizzas -" << endl;
        for(unsigned int i = 0; i < pizzas.size(); i++){
            cout << i + 1 << ". " << pizzas[i] << endl;
        }
    cout << endl;
    }
    else if(pizzas.empty()){
        cout << "There are no pizzas registered!" << endl;
    }

}
