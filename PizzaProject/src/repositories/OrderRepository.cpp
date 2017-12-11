#include "../../include/repositories/OrderRepository.h"

OrderRepository::OrderRepository()
{
    //ctor
}

OrderRepository::~OrderRepository()
{
    //dtor
}
void OrderRepository::addOrderToRepo(const Order& order){
    ofstream fout;
    fout.open("orders.dat", ios::binary|ios::app);

    order.write(fout);

    fout.close();
}

vector<Order> OrderRepository::getOrders(){
    ifstream fin;

    vector<Order> orders;

    fin.open("orders.dat", ios::binary);


    while(!fin.eof()){
        Order order;
        order.read(fin);

        if(fin.eof()){
            break;
        }

        orders.push_back(order);
    }
    fin.close();
    return orders;
}

