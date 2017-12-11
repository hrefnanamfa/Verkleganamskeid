#include "../../include/services/ExtrasService.h"

ExtrasService::ExtrasService()
{
    //ctor
}

ExtrasService::~ExtrasService()
{
    //dtor
}

Extras ExtrasService::getExtrasAt(int i){
    getExtras();
    return extras.at(i);
}

void ExtrasService::addExtras(Extras& extras){
    extrasrepository.addExtras(extras);
}

void ExtrasService::getExtras(){
    extras = extrasrepository.getExtras();
}

vector <Extras> ExtrasService::getExtrasVector(){
    return extras;
}

void ExtrasService::listAvailableExtras(){
    getExtras();
    for(unsigned int i = 0; i < extras.size(); i++){
        cout << i + 1  << ". " << extras[i] << endl;
    }
}
