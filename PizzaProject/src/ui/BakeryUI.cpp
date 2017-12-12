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
    cout << "Bakery" << endl;

    Workplaces workplace = workplacesui.selectWorkplace();

    string work = workplace.getName();


    while(selection != 'Q'){
        cout << "View Orders:" << endl;
        cout << "1. On hold" << endl;
        cout << "2. In making" << endl << endl;

        cout << "q: to go back" << endl;

        cin >> selection;
        selection = toupper(selection);
        cout << endl;

        if(selection == '1'){
                int select = 0;
                cout << "- Orders on hold -" << endl;
                orderui.listOrdersByStatus(work, 1);
                if (orderui.getisempty()){
                    cout << "There are no orders: ";
                    orderui.checkStatus(1);
                    cout << endl;
                    continue;
                }
                cout << "Select an order to flag as in making" << endl;
                cin >> select;
                cout << endl;
                Order order;
                order = orderservice.getOrderAt(select - 1, work);

                int selection = 0;
                cout << "Press:" << endl;
                cout << "2. to flag as in making" << endl;
                cin >> selection;
                order.setCurrentStatus(selection);//hérna breytist flaggið
                orderservice.replaceAndSaveOrderAt(select - 1, order, work);//hérna save-ast breytingin;
                cout << "Order was flagged as ";
                order.checkCurrentStatus();
                cout << endl << endl;

        }
        else if(selection == '2'){
            int select = 0;

            cout << "- Orders in making -" << endl;
            orderui.listOrdersByStatus(work, 2);
            if (orderui.getisempty()){
                cout << "There are no orders: ";
                orderui.checkStatus(2);
                cout << endl;
                continue;
            }

            cout << "Select an order to flag as ready" << endl;
            cin >> select;
            cout << endl;
            Order order;
            order = orderservice.getOrderAt(select - 1, work);

            int selection = 0;
            cout << "Press:" << endl;
            cout << "3. to flag as ready" << endl;
            cin >> selection;
            order.setCurrentStatus(selection);//hérna breytist flaggið
            orderservice.replaceAndSaveOrderAt(select - 1, order, work);
            cout << "Order was flagged as ";
            order.checkCurrentStatus();
            cout << endl << endl;

        }
    }
}
