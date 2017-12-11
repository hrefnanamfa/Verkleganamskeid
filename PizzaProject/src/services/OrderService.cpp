#include "../../include/services/OrderService.h"

OrderService::OrderService()
{
    //ctor
}

OrderService::~OrderService()
{
    //dtor
}

Order OrderService::makeOrder(vector<Pizza> pizzas, vector<Extras> extras, const bool& paid, Workplaces workplaces){
    Order order;
    order.setPizzas(pizzas);
    order.setExtras(extras);
    order.setPaid(paid);
    order.setPickup(workplaces);
    return order;
}

int OrderService::getPriceOfOrder(Order& order){
    return order.getPrice();
}

void OrderService::addOrder(Order& order){
    orderrepo.addOrderToRepo(order);
}

void OrderService::getOrderList(string work){
    orders = orderrepo.getOrders(work);
}

Order OrderService::getOrderAt(int i, string work){
    getOrderList(work);
    return orders.at(i);
}

void OrderService::listOrders(string work){
    getOrderList(work);
    for(unsigned int i = 0; i < orders.size(); i++){
        cout << i + 1 << ". " << orders.at(i) << endl;
    }
}
