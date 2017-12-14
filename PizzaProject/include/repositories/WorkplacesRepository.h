#ifndef WORKPLACESREPOSITORY_H
#define WORKPLACESREPOSITORY_H
#include "../models/Workplaces.h"
#include <fstream>
#include <vector>
#include <iostream>
#include "InvalidReadException.h"
#include "InvalidWriteException.h"

class WorkplacesRepository
{
    private:

    public:
        WorkplacesRepository();
        ~WorkplacesRepository();
        void addWorkplace(Workplaces& workplaces);
        void replaceWorkplacesInRepo(vector<Workplaces> workplaces);
        vector<Workplaces> getWorkplaces();

};


#endif // WORKPLACESREPOSITORY_H
