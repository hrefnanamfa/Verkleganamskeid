#ifndef TOPPINGUI_H
#define TOPPINGUI_H
#include "../models/Topping.h"
#include "../services/ToppingService.h"


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
        void listToppings();

};

#endif // TOPPINGUI_H