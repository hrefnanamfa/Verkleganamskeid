#ifndef TOPPINGREPOSITORY_H
#define TOPPINGREPOSITORY_H
#include <vector>
#include "../models/Topping.h"
#include <fstream>
#include <iostream>
#include "InvalidReadException.h"
#include "InvalidWriteException.h"

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
