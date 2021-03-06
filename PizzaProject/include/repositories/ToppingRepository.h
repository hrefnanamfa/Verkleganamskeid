#ifndef TOPPINGREPOSITORY_H
#define TOPPINGREPOSITORY_H
#include "../models/Topping.h"
#include "../exceptions/InvalidReadException.h"
#include "../exceptions/InvalidWriteException.h"

#include <vector>

class ToppingRepository
{
    private:

    public:
        void addTopping(Topping& topping);

        void replaceToppingsInRepo(vector<Topping> toppings);
        vector<Topping> getToppings();
};

#endif // TOPPINGREPOSITORY_H
