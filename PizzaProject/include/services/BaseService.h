#ifndef BASESERVICE_H
#define BASESERVICE_H
#include "BaseRepository.h"

class BaseService
{

    private:
        BaseRepository baserepository;

    public:
        BaseService();
        void addBase(Base& base);
        ~BaseService();

};

#endif // BASESERVICE_H
