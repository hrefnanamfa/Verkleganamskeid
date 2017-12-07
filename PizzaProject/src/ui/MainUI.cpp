#include "../../include/ui/MainUI.h"

MainUI::MainUI()
{
    //ctor
}


void MainUI::startUI(){
    char selection;
    do{
        cout << "Select the appropriate option:" << endl << endl;

        cout << "1. Register a price for a base pizza" << endl;
        cout << "2. Register toppings and price for each topping" << endl;
        cout << "3. List toppings and bases with price" << endl;
        cout << "4. Register an ordered pizza (and show price)" << endl;
        cout << "5. List pizzas made" << endl;
        cout << "q. For quit" << endl << endl;

        cin >> selection;
        cout << endl;

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

    }while(selection != 'q');

}
