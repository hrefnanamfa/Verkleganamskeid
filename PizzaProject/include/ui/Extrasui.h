#ifndef EXTRASUI_H
#define EXTRASUI_H
#include "../models/Extras.h"
#include "../services/ExtrasService.h"

#include <cstdlib>
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
        bool isExtrasVectorEmpty();
        void createExtras();
        void listExtras();
        void startUI();
        int inputSanitize(string input, int maxSize);
        int getExtrasVectorSize();
};

#endif // TOPPINGUI_H
