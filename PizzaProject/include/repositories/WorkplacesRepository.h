#ifndef WORKPLACESREPOSITORY_H
#define WORKPLACESREPOSITORY_H
#include "../models/Workplaces.h"
#include "InvalidReadException.h"
#include "InvalidWriteException.h"

#include <vector>

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
