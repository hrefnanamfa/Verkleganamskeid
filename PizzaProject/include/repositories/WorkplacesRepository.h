#ifndef WORKPLACESREPOSITORY_H
#define WORKPLACESREPOSITORY_H
#include "../models/Workplaces.h"
#include <fstream>
#include <vector>
#include <iostream>

class WorkplacesRepository
{
    private:

    public:
        WorkplacesRepository();
        ~WorkplacesRepository();
        void addWorkplace(Workplaces& workplaces);

        vector<Workplaces> getWorkplaces();

};


#endif // WORKPLACESREPOSITORY_H
