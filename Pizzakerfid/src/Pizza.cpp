#include "Pizza.h"


Pizza::Pizza()
{
    size.setSize(0);
    toppingCount = 0;
    toppings = 0;
    currentToppingNum = 0;
}

int Pizza::getToppingCount()const{
    return toppingCount;
}

void Pizza::setSize(int number){
    //size.setSize(number);
}


Pizza::Pizza(int numberOfToppings, int inches){
    toppingCount = numberOfToppings;
    toppings = new Topping[toppingCount];
    currentToppingNum = 0;
    size.setSize(inches);

}

Pizza::~Pizza()
{
    if(toppings != 0){
        delete[] toppings;
    }
}
void Pizza::addTopping(Topping topping){

    if(currentToppingNum < toppingCount){
        toppings[currentToppingNum] = topping;
        currentToppingNum++;
    }
}

ostream& operator <<(ostream& out, const Pizza& pizza){
    out << "Pizza with toppings:" << endl;

    for(int i = 0; i < pizza.toppingCount; i++){
        out << pizza.toppings[i] << endl;
    }

    return out;
}

istream& operator >>(istream& in, Pizza& pizza){

    //in >>
    return in;
}
