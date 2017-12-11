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
        cout << "Manager" << endl << endl;

        cout << "-Registries-" << endl;
        cout << "1. Add a base" << endl;
        cout << "2. Add a topping" << endl;
        cout << "3. Add a pizza to menu" << endl;
        cout << "4. Add an extra item" << endl;
        cout << "5. Add a workplace" << endl << endl;

        cout << "-View-" << endl;
        cout << "6. Toppings & bases" << endl;
        cout << "7. Pizza menu" << endl;
        cout << "8. Extras" << endl;
        cout << "9. Workplaces" << endl << endl;

        cout << "q. Go back" << endl;

        cin >> selection;

        selection = toupper(selection);

        PizzaUI pizzaui;

        if(selection == '1'){
            cout << "Making base" << endl;
            baseui.createBase();
        }
        else if(selection == '2'){
            cout << "Making topping" << endl;
            toppingui.createToppings();
        }
        else if(selection == '3'){
            cout << "Making pizza for menu" << endl;
            pizzaui.startUIpizzamenu();
        }
        else if(selection == '4'){
            cout << "Making item" << endl;
            extrasui.createExtras();
        }
        else if(selection == '5'){
            workplacesui.addWorkplace();
        }
        else if(selection == '6'){
            baseui.listBases();
            cout << endl;
            toppingui.listToppings();
            cout << endl;
        }
        else if(selection == '7'){
            pizzaui.listAvailablePizzas();
        }
        else if(selection == '8'){
            extrasui.listExtras();
        }
        else if(selection == '9'){
            workplacesui.listWorkplaces();
        }
        cout << endl;
    }
}
