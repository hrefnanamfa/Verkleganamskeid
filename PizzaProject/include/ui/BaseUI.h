#ifndef BASEUI_H
#define BASEUI_H
#include "Base.h"
#include "BaseService.h"

class BaseUI
{
    private:
        BaseService baseservice;
    public:
        BaseUI();
        void createBase();

        ~BaseUI();

};

#endif // BASEUI_H
