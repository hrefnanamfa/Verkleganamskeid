#include "../../include/services/BaseService.h"

BaseService::BaseService()
{
    //ctor
}

BaseService::~BaseService()
{
    //dtor
}

void BaseService::addBase(Base& base){
    baserepository.addBase(base);
}

void BaseService::getBases(){
    bases = baserepository.getBases();
}

void BaseService::listAvailableBases(){
    getBases();
    for(unsigned int i = 0; i < bases.size(); i++){
        cout << i + 1 << ". " << bases[i] << endl;
    }
}
