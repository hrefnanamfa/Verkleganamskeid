#ifndef DELIVERYUI_H
#define DELIVERYUI_H
#include "WorkplacesUI.h"
#include "../services/WorkplacesService.h"


class DeliveryUI
{
    public:
        DeliveryUI();
        virtual ~DeliveryUI();
        void startUI();

    private:
        WorkplacesUI workplacesui;
        WorkplacesService workplacesservice;
};

#endif // DELIVERYUI_H
