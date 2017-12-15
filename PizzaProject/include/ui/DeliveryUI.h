#ifndef DELIVERYUI_H
#define DELIVERYUI_H
#include "WorkplacesUI.h"
#include "../services/WorkplacesService.h"
#include "../ui/OrderUI.h"
#include "../ui/SalesUI.h"

class DeliveryUI
{
    private:
        WorkplacesUI workplacesui;
        WorkplacesService workplacesservice;
        OrderService orderservice;
        OrderUI orderui;
        SalesUI salesui;

    public:
        void startUI();
};

#endif // DELIVERYUI_H
