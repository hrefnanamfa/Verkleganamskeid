#ifndef EXTRASSERVICE_H
#define EXTRASSERVICE_H
#include "../repositories/ExtrasRepository.h"

class ExtrasService
{

    private:
        ExtrasRepository extrasrepository;
        vector <Extras> extras;

    public:
        ExtrasService();
        ~ExtrasService();
        Extras getExtrasAt(int i);

        void addExtras(Extras& extras);
        void getExtras();
        vector <Extras> getExtrasVector();
        void listAvailableExtras();
};

#endif // TOPPINGSERVICE_H
