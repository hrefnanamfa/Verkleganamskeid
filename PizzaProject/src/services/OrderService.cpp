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
