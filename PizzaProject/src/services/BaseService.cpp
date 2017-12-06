#include "BaseService.h"

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
