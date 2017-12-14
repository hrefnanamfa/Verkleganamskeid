#include "../../include/ui/BakeryUI.h"

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
    cout << "Choose your workplace" << endl;
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
<<<<<<< HEAD
                int select = 0;
                cout << "- Orders on hold -" << endl;
                orderui.listOrdersByStatus(work, 1);
                if (orderui.getisempty()){
                    cout << "There are no orders: ";
                    orderui.checkStatus(1);
                    cout << endl << endl;
                    continue;
                }
                cout << "Select an order to flag as in making" << endl;
                cin >> select;
                cout << endl;
                Order order;
                if(select > orderservice.getOrderVectorSize(work) || select < 0){
                    cout << "That order does not exist!" << endl << endl;
                }
                else{
                    order = orderservice.getOrderAt(select - 1, work);
                    if(order.getCurrentStatus() == 1){
=======
            int select = 0;
            cout << "- Orders on hold -" << endl;
            orderui.listOrdersByStatus(work, 1);
            if (orderui.getisempty()){
                cout << "There are no orders: ";
                orderui.checkStatus(1);
                cout << endl << endl;
                continue;
            }
            cout << "Select an order to flag as in making" << endl;
            cin >> select;
            cout << endl;
            Order order;
            if(select > orderservice.getOrderVectorSize(work) || select < 0){
                cout << "That order does not exist" << endl << endl;
            }
            else{
                order = orderservice.getOrderAt(select - 1, work);
                if(order.getCurrentStatus() == 1){
>>>>>>> 6f1a9f7688d3eafae0c760967daebb3e6d37399c
                        //int selection = 0;
                        //cout << "Press:" << endl;
                        //cout << "2. to flag as in making" << endl;
                        //cin >> selection;
                    order.setCurrentStatus(2);//hérna breytist flaggið
                    orderservice.replaceAndSaveOrderAt(select - 1, order, work);//hérna save-ast breytingin;
                    cout << "Order was flagged as: ";
                    orderui.checkStatus(order.getCurrentStatus());
                    cout << endl << endl;
                }
                else{
                    cout << "Invalid input!" << endl;
                }
            }
        }
        else if(selection == '2'){
            int select = 0;

            cout << "- Orders in making -" << endl;
            orderui.listOrdersByStatus(work, 2);
            if (orderui.getisempty()){
                cout << "There are no orders: ";
                orderui.checkStatus(2);
                cout << endl << endl;
                continue;
            }

            cout << "Select an order to flag as ready" << endl;
            cin >> select;
            cout << endl;
            if(select > orderservice.getOrderVectorSize(work) || select < 0){
                cout << "That order does not exist!" << endl << endl;
            }
            else{
                Order order;
                order = orderservice.getOrderAt(select - 1, work);
                if(order.getCurrentStatus() == 2){
                    //int selection = 0;
                    //cout << "Press:" << endl;
                    //cout << "3. to flag as ready" << endl;
                    //cin >> selection;
                    order.setCurrentStatus(3);//hérna breytist flaggið
                    orderservice.replaceAndSaveOrderAt(select - 1, order, work);
                    cout << "Order was flagged as: ";
                    orderui.checkStatus(order.getCurrentStatus());
                    cout << endl << endl;
                }
                else{
                    cout << "Invalid input!" << endl;
                }
            }
        }
    }
}
