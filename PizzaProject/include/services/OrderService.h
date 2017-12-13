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
        int getSizeOfOrders();
        int getPriceOfOrder(Order& order);
        Order makeOrder(vector<Pizza> pizzas, vector<Extras> extras, const bool& paid, Workplaces workplaces, string comment);
        void replaceAndSaveOrderAt(int i, Order& order, string work);
        void addOrder(Order& order);
        void getOrderList(string work);
        Order getOrderAt(int i, string work);
        vector<Order> getOrders(string work);
        void listOrders(string work);
};

#endif // ORDERSERVICE_H
