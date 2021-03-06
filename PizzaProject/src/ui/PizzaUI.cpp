#include "../../include/ui/PizzaUI.h"

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
            verbose = true;
            startUIpizzamenu();
        }
        else if (selection == '2'){
            string input;
            int select = 0;
            bool pizzasempty;
            do{
                listAvailablePizzas();
                pizzasempty = pizzas.empty();
                if(!pizzasempty){
                    cout << "Select a pizza to edit" << endl;
                    cin >> input;
                    select = baseui.inputSanitize(input, (int)getPizzaMenuSize() + 1);
                }
            }while(select < 0);
            if (!pizzasempty) {
                Pizza pizza;
                pizza = makeAPizza();
                pizzaservice.replaceAndSavePizzaAt(select - 1, pizza);
            }
        }
        else if (selection == '3'){
            string input;
            int select = 0;
            bool pizzasempty;
            do{
                listAvailablePizzas();
                pizzasempty = pizzas.empty();
                if(!pizzasempty){
                    cout << "Select a pizza to delete" << endl;
                    cin >> input;
                    select = baseui.inputSanitize(input, (int)getPizzaMenuSize() + 1);
                }
            }while(select < 0);
            if(!pizzasempty) {
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
    string input;
    string name;
    int numberOfToppings = 0;
    int choiceOfTopping = 0;
    int choiceOfBase = 0;
    int tempint;
    Base base;
    Topping topping;
    vector<Topping> toppings;
    Pizza pizza;

    pizzaservice.clearPizzas();

    if(!baseui.isBaseVectorEmpty()){
        if(!toppingui.isToppingVectorEmpty()){
            if(isVerbose()){
                cout << "What is the name of the pizza?" << endl;
                cin.ignore();
                getline(cin, name);
                pizza.setName(name);
            }
            do{
                baseui.listBases();
                cout << "Pick base: " << endl;
                cin >> input;
                choiceOfBase = baseui.inputSanitize(input, (int)baseui.getBaseVectorSize() + 1);
            }while(choiceOfBase <= 0);

            base = baseservice.getBaseAt(choiceOfBase - 1);
            cout << endl;
            do{
                cout << "How many toppings?" << endl;
                cin >> input;
                tempint = atoi(input.c_str());
                tempint++;
                stringstream ss;
                ss << tempint;
                input = ss.str();
                numberOfToppings = baseui.inputSanitize(input, 2147483647);
                numberOfToppings -= 1;
            }while(numberOfToppings < 0);

            if (numberOfToppings > 0) {
                cout << "Pick " << numberOfToppings << " toppings from list: " << endl;
                toppingui.listToppings();

                for(int i = 0; i < numberOfToppings; i++){
                    do{
                        cin >> input;
                        choiceOfTopping = baseui.inputSanitize(input, (int)toppingui.getToppingVectorSize() + 1);
                    }while(choiceOfTopping <= 0);

                    topping = toppingservice.getToppingAt(choiceOfTopping - 1);
                    toppings.push_back(topping);
                }
            }
            pizza = pizzaservice.makePizza(name, base, toppings);
        }
        else{
            toppingui.listToppings();
            throw InvalidPizzaException();
        }
    }
    else{
        baseui.listBases();
        throw InvalidPizzaException();
    }

    return pizza;
}

bool PizzaUI::isPizzaVectorEmpty(){
    if(pizzas.empty()){
        return true;
    }
    else{
        return false;
    }
}

void PizzaUI::startUIpizzamenu(){
    Pizza pizza;
    try{
        pizza = makeAPizza();
        pizzaservice.addPizza(pizza);

        cout << "You just registered: " << endl;
        cout << pizza << endl;
    }
    catch(InvalidPizzaException){
        cout << "Not possible to make pizza!" << endl;
    }
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

int PizzaUI::getPizzaMenuSize(){
    return this->pizzas.size();
}

void PizzaUI::setVerbose(bool verbose){
    this->verbose = verbose;
}

bool PizzaUI::isVerbose(){
    return verbose;
}
