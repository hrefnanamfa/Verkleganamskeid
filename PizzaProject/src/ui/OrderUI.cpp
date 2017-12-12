#include "../../include/ui/OrderUI.h"

OrderUI::OrderUI()
{
    //ctor
}

OrderUI::~OrderUI()
{
    //dtor
}

void OrderUI::listOrdersByStatus(string work, int status){
    orders = orderservice.getOrders(work);
    for(unsigned int i = 0; i < orders.size(); i++){
        if(orders.at(i).getStatus() == status){
            cout << orders.at(i) << endl;
        }
    }

    if(orders.size() == 0){
        cout << "There are no orders: ";
        checkStatus(status);
        return;
    }
    for(unsigned int i = 0; i < orders.size(); i++){
        if(orders.at(i).getStatus() == status){
            cout << orders.at(i) << endl;

        }
    }

}
void OrderUI::checkStatus(int i){
    if(i == 1){
        cout << "On hold" << endl;
    }
    else if(i == 2){
        cout << "In making" << endl;
    }
    else if(i == 3){
        cout << "Ready" << endl;
    }
    else if(i == 4){
        cout << "Delivered" << endl;
    }
}

