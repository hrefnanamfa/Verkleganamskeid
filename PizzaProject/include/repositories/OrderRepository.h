#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H
#include "../models/Order.h"
#include "../models/Workplaces.h"
#include "../exceptions/InvalidReadException.h"
#include "../exceptions/InvalidWriteException.h"

class OrderRepository
{

    private:
        Workplaces workplaces;

    public:
        vector<Order> getOrders(string work);
        void addOrderToRepo(Order& order);
        void replaceOrdersInRepo(vector<Order> orders, string workplace);
        void addComment(string comment);

};

#endif // ORDERREPOSITORY_H
