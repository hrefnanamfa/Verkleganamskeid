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

        if(selection == '1'){
            baseui.startUI();
        }
        else if(selection == '2'){
            toppingui.startUI();
        }
        else if(selection == '3'){
            pizzaui.startUI();
        }
        else if(selection == '4'){
            extrasui.startUI();
        }
        else if(selection == '5'){
            workplacesui.startUI();
        }
        cout << endl;
    }
}
