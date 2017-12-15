#ifndef EXTRASREPOSITORY_H
#define EXTRASREPOSITORY_H
#include "../models/Extras.h"
#include "../exceptions/InvalidReadException.h"
#include "../exceptions/InvalidWriteException.h"

#include <vector>

class ExtrasRepository
{

    private:

    public:
        void addExtras(Extras& extras);
        vector<Extras> getExtras();
        void replaceExtrasInRepo(vector<Extras> extras);

};

#endif // TOPPINGREPOSITORY_H
