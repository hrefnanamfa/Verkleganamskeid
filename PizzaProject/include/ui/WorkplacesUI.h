#ifndef WORKPLACESUI_H
#define WORKPLACESUI_H
#include "../services/WorkplacesService.h"
#include "../models/Workplaces.h"

#include <iostream>
using namespace std;

class WorkplacesUI
{
    private:
        WorkplacesService workplacesservice;

    public:
        WorkplacesUI();
        virtual ~WorkplacesUI();
        void addWorkplace();
        void listWorkplaces();
        Workplaces selectWorkplace();
};

#endif // WORKPLACESUI_H
