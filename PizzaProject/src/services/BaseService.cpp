#include "../../include/services/BaseService.h"

void BaseService::addBase(Base& base){
    baserepository.addBase(base);
}

void BaseService::getBases(){
    bases = baserepository.getBases();
}

Base BaseService::getBaseAt(int i){
    getBases();
    return bases.at(i);
}

vector<Base> BaseService::listAvailableBases(){
    getBases();
    return bases;
}

void BaseService::replaceAndSaveBaseAt(int i, Base& base){
    getBases();
    bases.at(i) = base;
    baserepository.replaceBasesInRepo(bases);
}

void BaseService::deleteBaseAtAndSave(int i){
    getBases();
    bases.erase(bases.begin() + i);
    baserepository.replaceBasesInRepo(bases);
}
