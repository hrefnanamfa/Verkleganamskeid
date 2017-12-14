#ifndef ORDERUI_H
#define ORDERUI_H
#include "../services/OrderService.h"
#include "EmptyOrderListException.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class OrderUI
{

    private:
        OrderService orderservice;
        vector<Order> orders;
        bool isempty;

    public:
        OrderUI();
        ~OrderUI();
        bool getisempty();
        void listOrdersByStatus(string work, int status);
        void checkStatus(int i);
        int inputSanitize(string input, int maxSize);

};

#endif // ORDERUI_H
