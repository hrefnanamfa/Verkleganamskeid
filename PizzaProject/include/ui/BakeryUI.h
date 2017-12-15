#ifndef BAKERYUI_H
#define BAKERYUI_H
#include "WorkplacesUI.h"
#include "../services/WorkplacesService.h"
#include "../services/OrderService.h"
#include "OrderUI.h"
#include "../exceptions/EmptyOrderListException.h"
#include "../exceptions/InvalidAnswerException.h"
class BakeryUI
{

    private:
        WorkplacesUI workplacesui;
        WorkplacesService workplacesservice;
        OrderService orderservice;
        OrderUI orderui;

    public:
        BakeryUI();
        virtual ~BakeryUI();
        void startUI();
};

#endif // BAKERYUI_H
