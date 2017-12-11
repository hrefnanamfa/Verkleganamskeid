#ifndef EXTRASREPOSITORY_H
#define EXTRASREPOSITORY_H
#include "../models/Extras.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class ExtrasRepository
{

    private:

    public:
        ExtrasRepository();
        ~ExtrasRepository();
        void addExtras(Extras& extras);

        vector<Extras> getExtras();
};

#endif // TOPPINGREPOSITORY_H
