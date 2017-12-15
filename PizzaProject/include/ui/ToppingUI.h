#ifndef TOPPINGUI_H
#define TOPPINGUI_H
#include "../models/Topping.h"
#include "../services/ToppingService.h"

#include <cstdlib>
#include <iostream>

using namespace std;

class ToppingUI
{
    private:
        ToppingService toppingservice;
        vector<Topping> toppings;

    public:
        ToppingUI();
        ~ToppingUI();
        bool isToppingVectorEmpty();
        void createTopping();
        void listToppings();
        void startUI();
        int getToppingVectorSize();
        int inputSanitize(string input, int maxSize);

};

#endif // TOPPINGUI_H
