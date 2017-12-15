#ifndef WORKPLACESREPOSITORY_H
#define WORKPLACESREPOSITORY_H
#include "../models/Workplaces.h"
#include "../exceptions/InvalidReadException.h"
#include "../exceptions/InvalidWriteException.h"

#include <vector>

class WorkplacesRepository
{
    private:

    public:
        void addWorkplace(Workplaces& workplaces);
        void replaceWorkplacesInRepo(vector<Workplaces> workplaces);
        vector<Workplaces> getWorkplaces();

};


#endif // WORKPLACESREPOSITORY_H
