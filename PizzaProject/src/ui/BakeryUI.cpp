#include "../../include/ui/BakeryUI.h"
#include <iostream>

using namespace std;

BakeryUI::BakeryUI()
{
    //ctor
}

BakeryUI::~BakeryUI()
{
    //dtor
}
void BakeryUI::startUI(){
    char selection = '\0';

    Workplaces workplace = workplacesui.selectWorkplace();

    string work = workplace.getName();


    while(selection != 'Q'){
        cout << "-- " << work << " --" << endl;
        cout << "-- View Orders:" << endl;
        cout << "1. On hold" << endl;
        cout << "2. In progress" << endl << endl;

        cout << "Q: Go back" << endl;

        cin >> selection;
        selection = toupper(selection);

        if(selection == '1'){
            int select = 0;
            cout << "- Orders on hold -" << endl;
            orderservice.listOrders(work);
            cout << "Select an order to flag";
            cin >> select;
            cout << select;
            Order order;
            order = orderservice.getOrderAt(select - 1, work);

            cout << "Select:" << endl;
            cout << "1. to flag as in process" << endl;
            cout << "2. to flag as ready" << endl;
            cin >> select;
            order.setCurrentStatus(select + 1);
            cout << "Order was flagged as ";
            order.checkCurrentStatus();

        }
        else if(selection == '2'){
            char select = '\0';
            cout << "-Orders in progress-" << endl;
            orderservice.listOrders(work);
            cout << "Select an order to flag";
            cin >> select;
        }
    }
    /*char selection = '\0';

    while(selection != 'Q'){

        cout << "Please pick an order to flag" << endl;

        //orderservice.listOrders();//List orders in process

        cin >> selection;
        selection = toupper(selection);

        if(selection == 'P') {

        }
        else if(selection == 'S') {

        }
        else if(selection == 'B') {

        }
        else if(selection == 'D') {

        }
    }*/
}
