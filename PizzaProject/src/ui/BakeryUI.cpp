#include "../../include/ui/BakeryUI.h"

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
            string input;
            int select;

                cout << "- Orders on hold -" << endl;
                orderui.listOrdersByStatus(work, 1);
                if (orderui.getisempty()){
                    cout << "There are no orders: ";
                    orderui.checkStatus(1);
                    cout << endl << endl;
                    continue;
                }
            do{
                cout << "Select an order to flag as in making" << endl;
                cin >> input;
                cout << endl;

                select = orderui.inputSanitize(input, orderservice.getOrderVectorSize(work) + 1);

            }while(select < 0);

            Order order;
            order = orderservice.getOrderAt(select - 1, work);

            if(order.getCurrentStatus() == 1){
                order.setCurrentStatus(2);//hérna breytist flaggið
                orderservice.replaceAndSaveOrderAt(select - 1, order, work);//hérna save-ast breytingin;
                cout << "Order was flagged as: ";
                orderui.checkStatus(order.getCurrentStatus());
                cout << endl << endl;
            }
            else {
                cout << "That order does not exist" << endl << endl;
            }
        }
        else if(selection == '2'){
            string input;
            int select;

                cout << "- Orders in making -" << endl;
                orderui.listOrdersByStatus(work, 2);
                if (orderui.getisempty()){
                    cout << "There are no orders: ";
                    orderui.checkStatus(2);
                    cout << endl << endl;
                    continue;
                }
            do{
                cout << "Select an order to flag as ready" << endl;
                cin >> input;
                cout << endl;

                select = orderui.inputSanitize(input, orderservice.getOrderVectorSize(work) + 1);

            }while(select < 0);
            Order order;
            order = orderservice.getOrderAt(select - 1, work);
            if(order.getCurrentStatus() == 2){
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
