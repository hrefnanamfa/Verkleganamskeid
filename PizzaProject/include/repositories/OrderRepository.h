#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H
#include "../models/Order.h"


class OrderRepository
{

    private:
    public:
        OrderRepository();
        ~OrderRepository();
        vector<Order> getOrders();
        void addOrderToRepo(const Order& order);

};

#endif // ORDERREPOSITORY_H
