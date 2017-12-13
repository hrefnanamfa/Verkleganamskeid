#ifndef BASEREPOSITORY_H
#define BASEREPOSITORY_H
#include "../models/Base.h"
#include <fstream>
#include <vector>
#include <iostream>


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
