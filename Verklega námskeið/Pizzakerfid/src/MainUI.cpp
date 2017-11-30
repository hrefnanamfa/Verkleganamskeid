#include "MainUI.h"


MainUI::MainUI()
{
    //ctor
}

MainUI::~MainUI()
{
    //dtor
}

void MainUI::startUI(){
    char selection = '\0';

    while(selection != 'q'){

        cout << "Please choose your position:" << endl;
        cout << "m: for manager" << endl;
        cout << "s: for sales person" << endl;
        cout << "b: for baker" << endl;
        cout << "d: for delivery man" << endl;
        cout << "q: for quit" << endl;

        cin >> selection;
        if(selection == 'm'){
            ManagerUI managerui;
            managerui.startUI();
        }

        else if(selection == 's'){
        }

        else if(selection == 'b'){

        }
        else if(selection == 'd'){

        }
    }
}
