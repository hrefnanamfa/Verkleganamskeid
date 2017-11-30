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
        cout << "m: Managing" << endl;
        cout << "s: Sales" << endl;
        cout << "b: Bakery" << endl;
        cout << "d: Delivery" << endl;
        cout << "q: Quit" << endl;

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
