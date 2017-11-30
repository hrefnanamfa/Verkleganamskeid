#include "ManagerUI.h"
#include "PizzaUI.h"

ManagerUI::ManagerUI()
{
    //ctor
}

ManagerUI::~ManagerUI()
{
    //dtor
}
void ManagerUI::startUI(){
    char selection = '\n';
    while (selection != 'Q'){
        cout << "Choose your appropriate option" << endl;
        cout << "p: Add a type of pizza" << endl;
        cout << "t: Add toppings" << endl;
        cout << "m: Make a menu" << endl;
        cout << "e: Add extras" << endl;
        cout << "d: Add delivery destination" << endl;
        cout << "q: to go back" << endl;

        cin >> selection;
        selection = toupper(selection);
        if(selection == 'P'){
            PizzaUI pizzaui;
            pizzaui.startUI();
        }

        else if(selection == 'T'){

        }

        else if(selection == 'M'){

        }
        else if(selection == 'E'){

        }
    }
}
