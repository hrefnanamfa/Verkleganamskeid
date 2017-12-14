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
        vector<Extras> extras;

    public:
        ExtrasUI();
        ~ExtrasUI();
        void createExtras();
        void listExtras();
        void startUI();


};

#endif // TOPPINGUI_H
