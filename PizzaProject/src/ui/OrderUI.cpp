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
    isempty = false;

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
        cout << "On hold";
    }
    else if(i == 2){
        cout << "In making";
    }
    else if(i == 3){
        cout << "Ready";
    }
    else if(i == 4){
        cout << "Delivered";
    }
}

int OrderUI::inputSanitize(string input, int maxSize) {
    int select;
    if (isdigit(input[0])){
        select = atoi(input.c_str());
        if (select >  0 && select < maxSize) {
            return select;
        }
        else {
            cout << "Selection does not exist" << endl << endl;
            return -1;
        }
    }
    else {
        cout << "Invalid input" << endl;
        return -1;
    }
}
