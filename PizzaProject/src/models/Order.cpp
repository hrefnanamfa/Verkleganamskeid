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

ostream& operator <<(ostream& out, Order& order){
    out << "Pizzas: ";

    for(unsigned int i = 0; i < order.pizzas.size(); i++){
        out << (i + 1) << ". " << order.pizzas.at(i) << endl;
    }
    out << "Status: " << order.currentStatus << endl;
    out << "Paid for? " << order.paid << endl;
    out << order.price << endl;

    return out;
}


