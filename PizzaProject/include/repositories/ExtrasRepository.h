#ifndef EXTRASREPOSITORY_H
#define EXTRASREPOSITORY_H
#include "../models/Extras.h"
#include "InvalidReadException.h"
#include "InvalidWriteException.h"

#include <vector>

using namespace std;

class ExtrasRepository
{

    private:

    public:
        ExtrasRepository();
        ~ExtrasRepository();
        void addExtras(Extras& extras);
        vector<Extras> getExtras();
        void replaceExtrasInRepo(vector<Extras> extras);

};

#endif // TOPPINGREPOSITORY_H
