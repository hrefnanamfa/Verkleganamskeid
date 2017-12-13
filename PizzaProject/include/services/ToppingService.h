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
        vector <Topping> listAvailableToppings();
        void replaceAndSaveToppingAt(int i, Topping& topping);
        void deleteToppingAtAndSave(int i);
};

#endif // TOPPINGSERVICE_H
