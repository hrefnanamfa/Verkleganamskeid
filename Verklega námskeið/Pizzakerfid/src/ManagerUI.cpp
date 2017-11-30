#include "ManagerUI.h"

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
    while (selection != 'q'){
        cout << "Choose your appropriate option" << endl;
        cout << "p: Add a type of pizza" << endl;
        cout << "t: Add toppings" << endl;
        cout << "m: Make a menu" << endl;
        cout << "e: Add extras" << endl;
        cout << "q: to go back" << endl;

        cin >> selection;
        if(selection == 'p'){

        }

        else if(selection == 't'){

        }

        else if(selection == 'm'){

        }
        else if(selection == 'e'){

        }
    }
}
