#ifndef TOPPINGREPOSITORY_H
#define TOPPINGREPOSITORY_H
#include "../models/Topping.h"
#include "InvalidReadException.h"
#include "InvalidWriteException.h"

#include <vector>

using namespace std;

class ToppingRepository
{

    private:

    public:
        ToppingRepository();
        ~ToppingRepository();
        void addTopping(Topping& topping);

        void replaceToppingsInRepo(vector<Topping> toppings);
        vector<Topping> getToppings();
};

#endif // TOPPINGREPOSITORY_H
