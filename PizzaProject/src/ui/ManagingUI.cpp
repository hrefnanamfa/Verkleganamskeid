#include "../../include/ui/ManagingUI.h"

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
        cout << "What would you like to manage?" << endl << endl;
        cout << "1. Register a new base with price" << endl;
        cout << "2. Register a new topping with price" << endl;
        cout << "3. Register a pizza for the menu (and show price)" << endl;
        cout << "4. Register an extra item" << endl;
        cout << "5. List toppings and bases" << endl;
        cout << "6. List pizza menu" << endl;
        cout << "7. List extra items" << endl;
        cout << "8. Add a workplace" << endl;
        cout << "9. List all workplaces" << endl;
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
            cout << "Making pizza for menu" << endl;

            pizzaui.startUIpizzamenu();
        }
        else if(selection == '4'){
            extrasui.createExtras();
        }
        else if(selection == '5'){
            baseui.listBases();
            cout << endl;
            toppingui.listToppings();
            cout << endl;
        }
        else if(selection == '6'){
            pizzaui.listAvailablePizzas();
        }
        else if(selection == '7'){
            extrasui.listExtras();
        }
        else if(selection == '8'){
            workplacesui.addWorkplace();//Skra afhendingarstad
        }
        else if(selection == '9'){
            workplacesui.listWorkplaces();
        }
        cout << endl;
    }
}
