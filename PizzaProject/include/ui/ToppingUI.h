#ifndef TOPPINGUI_H
#define TOPPINGUI_H
#include "ToppingService.h"
#include "../models/Topping.h"
#include <iostream>
using namespace std;

class ToppingUI
{
    private:
        ToppingService toppingservice;

    public:
        ToppingUI();
        ~ToppingUI();
        void createToppings();

};

#endif // TOPPINGUI_H
