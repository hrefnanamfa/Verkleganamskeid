#ifndef BASEREPOSITORY_H
#define BASEREPOSITORY_H
#include "../models/Base.h"
#include "InvalidReadException.h"
#include "InvalidWriteException.h"

#include <vector>

class BaseRepository
{
    private:

    public:
        BaseRepository();
        ~BaseRepository();
        void addBase(Base& base);

        vector<Base> getBases();
        void replaceBasesInRepo(vector<Base> bases);

};

#endif // BASEREPOSITORY_H
