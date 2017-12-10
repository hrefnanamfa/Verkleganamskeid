#include "OrderService.h"

OrderService::OrderService()
{
    //ctor
}

OrderService::~OrderService()
{
    //dtor
}

Order OrderService::makeOrder(vector<Pizza> pizzas, const bool& paid){
    Order order;
    order.setPizzas(pizzas);
    order.setPaid(paid);
    return order;
}

int OrderService::getPriceOfOrder(Order& order){
    return order.getPrice();
}

void OrderService::addOrder(const Order& order){
    orderrepo.addOrderToRepo(order);
}

void OrderService::getOrderList(){
    orders = orderrepo.getOrders();
}

void OrderService::listOrders(){
    getOrderList();
    for(unsigned int i = 0; i < orders.size(); i++){
        cout << i + 1 << ". " << orders.at(i) << endl;
    }
}
