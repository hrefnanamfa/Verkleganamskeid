#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H
#include "Order.h"
#include "OrderRepository.h"

class OrderService
{

    private:
        OrderRepository orderrepo;


    public:
        OrderService();
        ~OrderService();

        int getPriceOfOrder(Order& order);
        Order makeOrder(vector<Pizza> pizzas, const bool& paid);
};

#endif // ORDERSERVICE_H
