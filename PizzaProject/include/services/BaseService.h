#ifndef BASESERVICE_H
#define BASESERVICE_H
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
        vector<Base> listAvailableBases();
        void replaceAndSaveBaseAt(int i, Base& base);
        void deleteBaseAtAndSave(int i);
};

#endif // BASESERVICE_H
