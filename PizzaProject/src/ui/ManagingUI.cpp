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
        cout << "Manager" << endl;

        cout << "- Registries -" << endl;
        cout << "1. Base" << endl;
        cout << "2. Topping" << endl;
        cout << "3. Pizza for menu" << endl;
        cout << "4. Extra item" << endl;
        cout << "5. Workplace" << endl << endl;

        cout << "q. to go back" << endl;

        cin >> selection;

        selection = toupper(selection);

        PizzaUI pizzaui;

        if(selection == '1'){
            baseui.startUI();
        }
        else if(selection == '2'){
            toppingui.startUI();
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
            workplacesui.addWorkplace();//Skra afhendingarstad

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
            cout << "- Workplaces -" << endl;
            workplacesui.listWorkplaces();
        }
        cout << endl;
    }
}
