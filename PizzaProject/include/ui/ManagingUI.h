#ifndef MANAGINGUI_H
#define MANAGINGUI_H
#include "ToppingUI.h"
#include "BaseUI.h"
#include "PizzaUI.h"
#include "Extrasui.h"
#include "WorkplacesUI.h"

class ManagingUI
{
    public:
        ManagingUI();
        virtual ~ManagingUI();
        void startUI();

    protected:

    private:
        ToppingUI toppingui;
        BaseUI baseui;
        PizzaUI pizzaui;
        ExtrasUI extrasui;
        WorkplacesUI workplacesui;
};

#endif // MANAGINGUI_H
