#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H
#include "../repositories/ToppingRepository.h"


class ToppingService
{

    private:
        ToppingRepository toppingrepository;
        vector <Topping> toppings;

    public:
        ToppingService();
        ~ToppingService();
        Topping getToppingAt(int i);

        void addTopping(Topping& topping);
        void getToppings();
        vector <Topping> getToppingVector();
        void listAvailableToppings();
};

#endif // TOPPINGSERVICE_H
