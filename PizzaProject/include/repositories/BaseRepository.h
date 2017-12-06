#ifndef BASEREPOSITORY_H
#define BASEREPOSITORY_H
#include "Base.h"
#include <fstream>


class BaseRepository
{
    private:

    public:
        BaseRepository();
        ~BaseRepository();
        void addBase(Base& base);

};

#endif // BASEREPOSITORY_H
