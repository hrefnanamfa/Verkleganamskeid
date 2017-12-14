#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H
#include "../repositories/OrderRepository.h"

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
        Order makeOrder(vector<Pizza> pizzas, vector<Extras> extras, const bool& paid, Workplaces workplaces, string comment, bool pickup, string address, int addressNumber);
        void replaceAndSaveOrderAt(int i, Order& order, string work);
        void addOrder(Order& order);
        void getOrderList(string work);
        Order getOrderAt(int i, string work);
        vector<Order> getOrders(string work);
        void listOrders(string work);
        int getOrderVectorSize(string work);
};

#endif // ORDERSERVICE_H
