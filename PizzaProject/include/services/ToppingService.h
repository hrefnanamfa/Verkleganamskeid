#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H
#include "../models/Topping.h"
#include "../repositories/ToppingRepository.h"


class ToppingService
{

    private:
        ToppingRepository toppingrepository;
        vector <Topping> toppings;

    public:
        ToppingService();
        ~ToppingService();

        void addTopping(Topping& topping);
        void getToppings();
        vector <Topping> getToppingVector();
        void listAvailableToppings();
};

#endif // TOPPINGSERVICE_H
