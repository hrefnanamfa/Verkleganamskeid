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
    cout << "Delivery" << endl;

    Workplaces workplace = workplacesui.selectWorkplace();

    string work = workplace.getName();


    while(selection != 'Q'){
        cout << "View Orders:" << endl;
        cout << "1. On hold & in making" << endl;
        cout << "2. Ready" << endl << endl;

        cout << "q: to go back" << endl;

        cin >> selection;
        selection = toupper(selection);
        cout << endl;

        if(selection == '1'){
            cout << "- Orders on hold & in making -" << endl << endl;
            orderui.listOrdersByStatus(work, 1);
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

            char answer = 0;
            cout << "Has the order been paid for? (y/n)" << endl;
            cin >> answer;
            bool paidfor = salesui.checkAnswer(answer);

            order.setPaid(paidfor);

            if(!order.checkPaid()){
                cout << "The order hasn't been paid for!" << endl;
                continue;
            }
            int choice = 0;
            cout << "Press:" << endl;
            cout << "4. to flag as delivered" << endl;
            cin >> choice;
            order.setCurrentStatus(choice);
            orderservice.replaceAndSaveOrderAt(select - 1, order, work);

            if(order.getStatus() == 4){
                cout << "Order was flagged as: ";
                order.checkCurrentStatus();
            }
            cout << endl;
        }
    }
}
