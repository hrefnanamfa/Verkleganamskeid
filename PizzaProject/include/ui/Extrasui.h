#ifndef EXTRASUI_H
#define EXTRASUI_H
#include "../models/Extras.h"
#include "../services/ExtrasService.h"

#include <iostream>

using namespace std;

class ExtrasUI
{
    private:
        ExtrasService extrasservice;

    public:
        ExtrasUI();
        ~ExtrasUI();
        void createExtras();
        void listExtras();

};

#endif // TOPPINGUI_H
