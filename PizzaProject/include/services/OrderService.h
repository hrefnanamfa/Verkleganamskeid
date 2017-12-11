#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H
#include "../models/Order.h"
#include "../repositories/OrderRepository.h"
#include "../models/Workplaces.h"

class OrderService
{

    private:
        OrderRepository orderrepo;
        vector<Order> orders;


    public:
        OrderService();
        ~OrderService();

        int getPriceOfOrder(Order& order);
        Order makeOrder(vector<Pizza> pizzas, vector<Extras> extras, const bool& paid, Workplaces workplaces);
        void addOrder(Order& order);
        void getOrderList(string work);
        Order getOrderAt(int i, string work);
        void listOrders(string work);
};

#endif // ORDERSERVICE_H
