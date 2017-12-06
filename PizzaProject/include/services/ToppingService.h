#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H
#include "../models/Topping.h"
#include "ToppingRepository.h"


class ToppingService
{

    private:
        ToppingRepository toppingrepository;
        vector <Topping> toppings;

    public:
        ToppingService();
        ~ToppingService();
        void addTopping(Topping& topping);
        void listToppings();

};

#endif // TOPPINGSERVICE_H
