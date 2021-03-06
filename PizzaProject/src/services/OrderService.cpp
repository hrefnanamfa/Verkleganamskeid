#include "../../include/services/OrderService.h"

int OrderService::getOrderVectorSize(string work){
    getOrderList(work);
    return orders.size();
}

Order OrderService::makeOrder(vector<Pizza> pizzas, vector<Extras> extras, const bool& paid, Workplaces workplaces, string comment, bool pickup, string address, int addressNumber){
    Order order;
    order.setPizzas(pizzas);
    order.setExtras(extras);
    order.setPaid(paid);
    order.setWorkplace(workplaces);
    order.setComment(comment);
    order.setPickup(pickup);
    order.setAddress(address, addressNumber);
    return order;
}

int OrderService::getPriceOfOrder(Order& order){
    return order.getPrice();
}

int OrderService::getSizeOfOrders(){
    return orders.size();
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

vector<Order> OrderService::getOrders(string work){
    getOrderList(work);
    return orders;
}

void OrderService::replaceAndSaveOrderAt(int i, Order& order, string work){
    getOrderList(work);                                     //fyllir vectorinn af orders ur skjalinu
    orders.at(i) = order;                                   //breytir order � �kve�num sta�i
    orderrepo.replaceOrdersInRepo(this->orders, work);      //save-ar n�ja vektorinn
}

void OrderService::listOrders(string work){
    getOrderList(work);
    for(unsigned int i = 0; i < orders.size(); i++){
        cout << "#" << i + 1 << endl;
        cout << orders.at(i) << endl;
    }
}
