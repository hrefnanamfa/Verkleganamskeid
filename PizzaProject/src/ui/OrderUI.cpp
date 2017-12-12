#include "../../include/ui/OrderUI.h"

OrderUI::OrderUI()
{
    isempty = false;
}

OrderUI::~OrderUI()
{
    //dtor
}

void OrderUI::listOrdersByStatus(string work, int status){
    int counter = 0;
    orders = orderservice.getOrders(work);

    for(unsigned int i = 0; i < orders.size(); i++){
        if(orders.at(i).getStatus() == status){
            cout << "#" << i + 1<< endl;
            cout << orders.at(i) << endl;
            counter ++;
        }
    }

    if (counter == 0){
        isempty = true;
    }
}
bool OrderUI::getisempty(){

    return this->isempty;
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

