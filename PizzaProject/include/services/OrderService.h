#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H
#include "Order.h"
#include "OrderRepository.h"

class OrderService
{

    private:
        OrderRepository orderrepo;
        vector<Order> orders;


    public:
        OrderService();
        ~OrderService();

        int getPriceOfOrder(Order& order);
        Order makeOrder(vector<Pizza> pizzas, const bool& paid);
        void addOrder(const Order& order);
        void getOrderList();
        void listOrders();
};

#endif // ORDERSERVICE_H
