#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>
using namespace std;

class Topping
{
    private:
        string name;
        double price;

    public:
        Topping();
        virtual ~Topping();
        friend ostream& operator <<(ostream&out, const Topping& topping);

};

#endif // TOPPING_H
