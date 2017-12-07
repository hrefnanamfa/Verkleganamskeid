#ifndef BASESERVICE_H
#define BASESERVICE_H
#include "../models/Base.h"
#include "../repositories/BaseRepository.h"

class BaseService
{

    private:
        BaseRepository baserepository;
        vector<Base> bases;

    public:
        BaseService();
        ~BaseService();

        Base getBaseAt(int i);
        void addBase(Base& base);
        void getBases();
        void listAvailableBases();
};

#endif // BASESERVICE_H
