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

    while(selection != 'Q'){

        cout << "Please choose your position:" << endl;
        cout << "m: for manager" << endl;
        cout << "s: for sales" << endl;
        cout << "b: for baker" << endl;
        cout << "d: for delivery" << endl;
        cout << "q: for quit" << endl;

        cin >> selection;
        selection = toupper(selection);

        if(selection == 'M') {
            ManagerUI managerui;
            managerui.startUI();
        }
        else if(selection == 'S') {
            SalesUI salesui;
            salesui.startUI();
        }
        else if(selection == 'B') {
            BakeUI bakeui;
            bakeui.startUI();
        }
        else if(selection == 'D') {
            DeliveryUI deliveryUI;
            deliveryUI.startUI();
        }
    }
}
