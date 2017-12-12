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
    string filename = order.getLocation() + ".dat";
    fout.open(filename.c_str(), ios::binary|ios::app);

    order.write(fout);

    fout.close();
}

void OrderRepository::replaceOrdersInRepo(vector<Order> orders, string workplace){
    ofstream fout;
    string filename = workplace + ".dat";

    fout.open(filename.c_str(), ios::binary);

    for(unsigned int i = 0; i < orders.size(); i++){
        orders.at(i).write(fout);
    }

    fout.close();
}

vector<Order> OrderRepository::getOrders(string work){
    ifstream fin;
    vector<Order> orders;
    string filename = work + ".dat";

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

