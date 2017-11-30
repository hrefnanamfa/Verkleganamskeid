#ifndef MAINUI_H
#define MAINUI_H
#include <iostream>
#include <string>
#include "ManagerUI.h"
#include "SalesUI.h"
#include "BakeUI.h"
#include "DeliveryUI.h"

using namespace std;

class MainUI
{
    private:

    public:
        MainUI();
        virtual ~MainUI();

        void startUI();
};

#endif // MAINUI_H
