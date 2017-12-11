#ifndef WORKPLACESSERVICE_H
#define WORKPLACESSERVICE_H
#include "../models/Workplaces.h"
#include "../repositories/WorkplacesRepository.h"

class WorkplacesService
{
    private:
        WorkplacesRepository workplacesrepository;
        vector<Workplaces> workplaces;

    public:
        WorkplacesService();
        ~WorkplacesService();

        Workplaces getWorkplaceAt(int i);
        void addWorkplace(Workplaces& workplaces);
        void getWorkplaces();
        void listAvailableWorkplaces();
        int workplacesAmount();
};
#endif // WORKPLACESSERVICE_H
