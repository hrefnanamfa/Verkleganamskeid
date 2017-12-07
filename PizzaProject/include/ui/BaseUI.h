#ifndef BASEUI_H
#define BASEUI_H
#include "../models/Base.h"
#include "../services/BaseService.h"

class BaseUI
{
    private:
        BaseService baseservice;
    public:
        BaseUI();
        void createBase();
        void listBases();

        ~BaseUI();

};

#endif // BASEUI_H
