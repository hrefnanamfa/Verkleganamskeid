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


        cout << "Q: Go back" << endl;

        cin >> selection;
        selection = toupper(selection);

        if(selection == 'M') {

        }
        else if(selection == 'S') {

        }
        else if(selection == 'B') {

        }
        else if(selection == 'D') {

        }
    }
}
