#include "../../include/ui/MainUI.h"
#include "InvalidReadException.h"
#include "InvalidWriteException.h"

MainUI::MainUI()
{
    //ctor
}

void MainUI::startUI(){
    char selection;
    do{
        cout << "Please choose your position:" << endl;
        cout << "m: Managing" << endl;
        cout << "s: Sales" << endl;
        cout << "b: Bakery" << endl;
        cout << "d: Delivery" << endl;
        cout << "q: Quit" << endl;

        cin >> selection;
        selection = toupper(selection);
        cout << endl;

        if(selection == 'M') {
            ManagingUI managingui;
            managingui.startUI();
        }
        else if(selection == 'S') {
            SalesUI salesui;
            salesui.startUI();
        }
        else if(selection == 'B') {
            BakeryUI bakeryui;
            bakeryui.startUI();
        }
        else if(selection == 'D') {
            DeliveryUI deliveryUI;
            deliveryUI.startUI();
        }

    }while(selection != 'Q');

    }
