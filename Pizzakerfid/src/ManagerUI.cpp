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
    while (selection != 'Q' || selection != 'q'){
        cout << "What would you like to manage?" << endl;
        cout << "1: Pizza size" << endl;
        cout << "2: Pizza type" << endl;
        cout << "3: Toppings" << endl;
        cout << "4: Menu" << endl;
        cout << "5: Extras" << endl;
        cout << "6: Delivery location" << endl;
        cout << "q: Go back" << endl;

        cin >> selection;

        PizzaUI pizzaui;

        if(selection == '1'){
            pizzaui.startUIsize();
        }
        else if(selection == '2'){

        }
        else if(selection == '3'){
            pizzaui.startUItopping();
        }
        else if(selection == '4'){

        }
        else if(selection == '5'){

        }
        else if(selection == '6'){

        }

    }
}
