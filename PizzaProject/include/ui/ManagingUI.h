#ifndef MANAGINGUI_H
#define MANAGINGUI_H
#include "ToppingUI.h"
#include "BaseUI.h"
#include "PizzaUI.h"
#include "Extrasui.h"
#include "WorkplacesUI.h"

class ManagingUI
{
    private:
        ToppingUI toppingui;
        BaseUI baseui;
        PizzaUI pizzaui;
        ExtrasUI extrasui;
        WorkplacesUI workplacesui;

    public:
        void startUI();
};

#endif // MANAGINGUI_H
