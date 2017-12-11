#ifndef BAKERYUI_H
#define BAKERYUI_H
#include "WorkplacesUI.h"
#include "../services/WorkplacesService.h"
#include "../services/OrderService.h"

class BakeryUI
{

    private:
        WorkplacesUI workplacesui;
        WorkplacesService workplacesservice;
        OrderService orderservice;

    public:
        BakeryUI();
        virtual ~BakeryUI();
        void startUI();
};

#endif // BAKERYUI_H
