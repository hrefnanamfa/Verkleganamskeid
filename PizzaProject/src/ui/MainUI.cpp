#include "../../include/ui/MainUI.h"

MainUI::MainUI()
{
    //ctor
}

void MainUI::startUI(){
    char selection;
    WorkplacesUI workplacesui;
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
            if (!workplacesui.isWorkplacesVectorEmpty()){
                bakeryui.startUI();
            }
        }
        else if(selection == 'D') {
            DeliveryUI deliveryUI;
            if (!workplacesui.isWorkplacesVectorEmpty()){
                deliveryUI.startUI();
            }
        }

    }while(selection != 'Q');

    }
