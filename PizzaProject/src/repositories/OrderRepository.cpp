#include "../../include/repositories/OrderRepository.h"

OrderRepository::OrderRepository()
{
    //ctor
}

OrderRepository::~OrderRepository()
{
    //dtor
}
void OrderRepository::addOrderToRepo(Order& order){
    ofstream fout;
    string filename = order.getPickup() + ".dat";
    fout.open(filename.c_str(), ios::binary|ios::app);

    order.write(fout);

    fout.close();
}

vector<Order> OrderRepository::getOrders(){
    ifstream fin;
    string filename = workplaces.getName() + ".dat";
    vector<Order> orders;

    fin.open(filename.c_str(), ios::binary);


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

