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
    cout << "Bakery" << endl;

    Workplaces workplace = workplacesui.selectWorkplace();

    string work = workplace.getName();


    while(selection != 'Q'){
        cout << "View Orders:" << endl;
        cout << "1. On hold & in making" << endl;
        cout << "2. Ready" << endl << endl;

        cout << "q: to go back" << endl;

        cin >> selection;
        selection = toupper(selection);

        if(selection == '1'){
            cout << "- Orders on hold -" << endl;
            orderui.listOrdersByStatus(work, 1);
            cout << "- Orders in making -" << endl;
            orderui.listOrdersByStatus(work, 2);
        }
        else if(selection == '2'){
            int select = 0;
            cout << "- Ready orders -" << endl;
            orderui.listOrdersByStatus(work, 3);
            cout << "Select and order to flag" << endl;
            cin >> select;
            cout << endl;
            Order order;
            order = orderservice.getOrderAt(select - 1, work);
            char selection = 0;
            cout << "Has the order been paid for? (y/n)" << endl;
            cin >> selection;
            salesui.checkAnswer(selection);
            if(order.checkPaid()){
                cout << "The order hasn't been paid for!";
                continue;
            }

            orderservice.replaceAndSaveOrderAt(select - 1, order, work);
            cout << "Order was flagged as ";
            order.checkCurrentStatus();
            cout << endl;
        }
    }
}
