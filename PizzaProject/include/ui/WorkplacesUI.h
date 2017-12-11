#ifndef WORKPLACESUI_H
#define WORKPLACESUI_H
#include "../services/WorkplacesService.h"
#include "../models/Workplaces.h"

#include <iostream>
using namespace std;

class WorkplacesUI
{
    public:
        WorkplacesUI();
        virtual ~WorkplacesUI();
        void addWorkplace();
        void listWorkplaces();

    protected:

    private:
        WorkplacesService workplacesservice;
};

#endif // WORKPLACESUI_H
