#ifndef ORDERUI_H
#define ORDERUI_H
#include "../services/OrderService.h"

class OrderUI
{

    private:
        OrderService orderservice;

    public:
        OrderUI();
        ~OrderUI();
        void makeNewPizza();

};

#endif // ORDERUI_H
