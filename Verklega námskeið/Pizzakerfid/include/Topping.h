#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>

using namespace std;

class Topping
{
    private:
        char name[32];
        double price;

    public:
        Topping();
        Topping (char *name, double price);
        virtual ~Topping();

        friend ostream& operator <<(ostream& out, const Topping& topping);
        friend istream& operator >>(istream& out, Topping& topping);

};

#endif // TOPPING_H
