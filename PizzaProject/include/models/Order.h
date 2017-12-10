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
        void setPrice();
        int getPrice();
        void setPizzas(vector<Pizza> pizzas);
        void setPaid(bool paid);
        void checkPaid();
        void checkCurrentStatus();
        friend ostream& operator <<(ostream& out, Order& order);
        friend istream& operator >>(istream& in, Order& order);

};

#endif // ORDER_H
