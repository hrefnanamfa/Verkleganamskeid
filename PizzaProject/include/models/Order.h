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
        int price;
    public:
        Order();
        ~Order();
        void setPizzas(vector<Pizza> pizzas);
        void setPaid(bool paid);
        friend ostream& operator <<(ostream& out, Order& order);

};

#endif // ORDER_H
