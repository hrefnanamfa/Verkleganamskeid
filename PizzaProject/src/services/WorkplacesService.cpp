#include "../../include/services/WorkplacesService.h"

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

vector<Workplaces> WorkplacesService::listAvailableWorkplaces(){
    getWorkplaces();
    return workplaces;
}

int WorkplacesService::workplacesAmount(){
    getWorkplaces();
    return workplaces.size();
}

void WorkplacesService::replaceAndSaveWorkplaceAt(int i, Workplaces& workplace){
    getWorkplaces();
    workplaces.at(i) = workplace;
    workplacesrepository.replaceWorkplacesInRepo(this->workplaces);
}

void WorkplacesService::deleteWorkplaceAtAndSave(int i){
    getWorkplaces();
    workplaces.erase(workplaces.begin() + i);
    workplacesrepository.replaceWorkplacesInRepo(this->workplaces);
}
