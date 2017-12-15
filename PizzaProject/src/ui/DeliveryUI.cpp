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
    cout << "Choose your workplace" << endl;

    Workplaces workplace = workplacesui.selectWorkplace();

    string work = workplace.getName();


    while(selection != 'Q'){
        cout << "1. View Orders: On hold & in making" << endl;
        cout << "2. Deliver orders that are ready" << endl << endl;

        cout << "q: to go back" << endl;

        cin >> selection;
        selection = toupper(selection);
        cout << endl;

        if(selection == '1'){
            cout << "- Orders on hold -" << endl << endl;
            orderui.listOrdersByStatus(work, 1);
            if (orderui.getisempty()){
                cout << "There are no orders: ";
                orderui.checkStatus(1);
                cout << endl;

            }
            cout << endl << "- Orders in making -" << endl << endl;
            orderui.listOrdersByStatus(work, 2);
            if (orderui.getisempty()){
                cout << "There are no orders: ";
                orderui.checkStatus(2);
                cout << endl << endl;
                continue;
            }
        }
        else if(selection == '2'){
            string input;
            int select;

            cout << "- Ready orders -" << endl;
            orderui.listOrdersByStatus(work, 3);
            if (orderui.getisempty()){
                cout << "There are no orders: ";
                orderui.checkStatus(3);
                cout << endl << endl;
                continue;
            }
            do{
                cout << "Select an order to flag as delivered" << endl;
                cin >> input;
                cout << endl;

                select = orderui.inputSanitize(input, orderservice.getOrderVectorSize(work) + 1);

            }while(select < 0);

            Order order;
            order = orderservice.getOrderAt(select - 1, work);
            if(order.getCurrentStatus() == 3){
                if(!order.checkPaid()){
                    char answer = 0;
                    cout << "Has the order been paid for? (y/n)" << endl;
                    cin >> answer;
                    bool paidfor = salesui.checkAnswer(answer);

                    order.setPaid(paidfor);
                }
                if(!order.checkPaid()){
                    cout << "You can't deliver an order that hasn't been paid for!" << endl;
                    continue;
                }
                order.setCurrentStatus(4);
                orderservice.replaceAndSaveOrderAt(select - 1, order, work);
                cout << "Order was flagged as: ";
                orderui.checkStatus(order.getCurrentStatus());
                cout << endl;
            }
            else{
                cout << "Invalid input!" << endl;
            }
            cout << endl;
        }
    }
}
