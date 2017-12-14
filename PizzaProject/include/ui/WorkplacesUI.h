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
        vector<Workplaces> workplaces;
    public:
        WorkplacesUI();
        virtual ~WorkplacesUI();
        void startUI();
        void addWorkplace();
        void listWorkplaces();
        Workplaces selectWorkplace();
};

#endif // WORKPLACESUI_H
