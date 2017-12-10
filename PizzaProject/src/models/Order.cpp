#include "Order.h"

Order::Order()
{
    this->paid = false;
    this->currentStatus = INPROGRESS;
    this->price = 0;
}

Order::~Order()
{
    //dtor
}

void Order::setPizzas(vector<Pizza> pizzas){
    this->pizzas = pizzas;
}

void Order::setPaid(bool paid){
    this->paid = paid;
}

void Order::setPrice(){
    int currentPrice = 0;

    for(unsigned int i = 0; i < pizzas.size(); i++){
        currentPrice += pizzas.at(i).getPriceOfPizza();
    }

    this->price = currentPrice;
}

int Order::getPrice() {
    setPrice();
    return this->price;
}
void Order::checkPaid(){
    if(this->paid == true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
void Order::checkCurrentStatus(){
    if(this->currentStatus == 1){
        cout << "In progress" << endl;
    }
    else if(this->currentStatus == 2){
        cout << "Ready" << endl;
    }
    else{
        cout << "Delivered" << endl;
    }
}



istream& operator >>(istream& in, Order& order){

}

ostream& operator <<(ostream& out, Order& order){
    out << "Pizzas: " << endl;

    for(unsigned int i = 0; i < order.pizzas.size(); i++){
        out << (i + 1) << ". " << order.pizzas.at(i) << endl;
    }
    out << "Status: ";
    order.checkCurrentStatus();

    out << "Paid for? ";
    order.checkPaid();

    out << "Cost: " << order.getPrice() << "kr." << endl;
    out << endl;

    return out;
}


