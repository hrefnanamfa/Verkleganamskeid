#ifndef BASEUI_H
#define BASEUI_H
#include "../models/Base.h"
#include "../services/BaseService.h"

#include <cstdlib>

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
        bool isBaseVectorEmpty();
        int getBaseVectorSize();
        int inputSanitize(string input, int maxSize);

        ~BaseUI();

};

#endif // BASEUI_H
