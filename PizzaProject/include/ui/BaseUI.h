#ifndef BASEUI_H
#define BASEUI_H
#include "../models/Base.h"
#include "../services/BaseService.h"

class BaseUI
{
    private:
        BaseService baseservice;
        vector<Base> bases;
    public:
        BaseUI();
        void startUI();
        void createBase();
        void listBases();

        ~BaseUI();

};

#endif // BASEUI_H
