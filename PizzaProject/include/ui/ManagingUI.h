#ifndef MANAGINGUI_H
#define MANAGINGUI_H
#include "ToppingUI.h"
#include "BaseUI.h"
#include "PizzaUI.h"

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
};

#endif // MANAGINGUI_H
