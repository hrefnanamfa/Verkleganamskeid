#include "ToppingRepository.h"

ToppingRepository::ToppingRepository()
{
    //ctor
}

ToppingRepository::~ToppingRepository()
{
    //dtor
}

void ToppingRepository::addTopping(Topping& topping){
    ofstream fout;

    fout.open("topping.dat", ios::binary|ios::app);

    fout.write((char*)(&topping), sizeof(Topping));
    fout.close();

}

vector<Topping> ToppingRepository::addToppings(){
    ifstream fin;
}

