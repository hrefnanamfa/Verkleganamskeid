#include "../../include/services/ExtrasService.h"

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

vector<Extras> ExtrasService::listAvailableExtras(){
    getExtras();
    return extras;
}

void ExtrasService::replaceAndSaveExtraAt(int i, Extras& extra){
    getExtras();
    extras.at(i) = extra;
    extrasrepository.replaceExtrasInRepo(this->extras);
}

void ExtrasService::deleteExtraAndSaveAt(int i){
    getExtras();
    extras.erase(extras.begin() + i);
    extrasrepository.replaceExtrasInRepo(this->extras);
}

