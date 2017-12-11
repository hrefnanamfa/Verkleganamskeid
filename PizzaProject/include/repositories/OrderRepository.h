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

};

#endif // ORDERREPOSITORY_H
