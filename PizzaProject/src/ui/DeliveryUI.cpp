#include "../../include/ui/DeliveryUI.h"
#include <iostream>

using namespace std;

DeliveryUI::DeliveryUI()
{
    //ctor
}

DeliveryUI::~DeliveryUI()
{
    //dtor
}
void DeliveryUI::startUI(){
    char selection = '\0';

    Workplaces workplace = workplacesui.selectWorkplace();

    string work = workplace.getName();


    while(selection != 'Q'){
        cout << "-- " << work << " --" << endl;
        cout << "-- View Orders:" << endl;
        cout << "1. On hold & in progress" << endl;
        cout << "2. Ready" << endl << endl;

        cout << "Q: Go back" << endl;

        cin >> selection;
        selection = toupper(selection);

        if(selection == '1'){
            orderservice.listOrders(work);
        }
        else if(selection == '2'){

        }
    }
}
