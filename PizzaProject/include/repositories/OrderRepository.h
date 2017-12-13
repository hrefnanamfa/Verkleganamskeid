#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H
#include "../models/Order.h"
#include "../models/Workplaces.h"


class OrderRepository
{

    private:
        Workplaces workplaces;

    public:
        OrderRepository();
        ~OrderRepository();
        vector<Order> getOrders(string work);
        void addOrderToRepo(Order& order);
        void replaceOrdersInRepo(vector<Order> orders, string workplace);
        void addComment(string comment);

};

#endif // ORDERREPOSITORY_H
