#ifndef MAINUI_H
#define MAINUI_H
#include <iostream>
#include "ToppingUI.h"
#include "BaseUI.h"
#include "PizzaUI.h"
using namespace std;

class MainUI
{

    private:
        ToppingUI toppingui;
        BaseUI baseui;
        PizzaUI pizzaui;

    public:
        MainUI();
        void startUI();


};

#endif // MAINUI_H
