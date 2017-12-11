#ifndef BAKERYUI_H
#define BAKERYUI_H
#include "../services/OrderService.h"

class BakeryUI
{

    private:
        OrderService orderservice;

    public:
        BakeryUI();
        virtual ~BakeryUI();
        void startUI();

};

#endif // BAKERYUI_H
