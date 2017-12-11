#include "WorkplacesService.h"

WorkplacesService::WorkplacesService()
{
    //ctor
}

WorkplacesService::~WorkplacesService()
{
    //dtor
}

void WorkplacesService::addWorkplace(Workplaces& workplaces){
    workplacesrepository.addWorkplace(workplaces);
}

void WorkplacesService::getWorkplaces(){
    workplaces = workplacesrepository.getWorkplaces();
}
Workplaces WorkplacesService::getWorkplaceAt(int i){
    getWorkplaces();
    return workplaces.at(i);
}

void WorkplacesService::listAvailableWorkplaces(){
    getWorkplaces();
    for(unsigned int i = 0; i < workplaces.size(); i++){
        cout << i + 1 << ". " << workplaces[i] << endl;
    }
}
