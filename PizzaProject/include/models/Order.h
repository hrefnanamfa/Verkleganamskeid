#ifndef ORDER_H
#define ORDER_H
#include "Pizza.h"

enum status { INPROGRESS = 1, READY, DELIVERED};


class Order
{
    private:
        vector<Pizza> pizzas;
        bool paid;
        status currentStatus;

    public:
        Order();
        ~Order();
};

#endif // ORDER_H
