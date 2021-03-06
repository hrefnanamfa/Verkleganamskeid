#ifndef WORKPLACESUI_H
#define WORKPLACESUI_H
#include "../services/WorkplacesService.h"
#include "../models/Workplaces.h"
#include "../exceptions/InvalidAnswerException.h"

#include <cstdlib>

class WorkplacesUI
{
    private:
        WorkplacesService workplacesservice;
        vector<Workplaces> workplaces;

    public:
        bool isWorkplacesVectorEmpty();
        void startUI();
        void addWorkplace();
        void listWorkplaces();
        Workplaces selectWorkplace();
        int inputSanitize(string input, int maxSize);
};

#endif // WORKPLACESUI_H
