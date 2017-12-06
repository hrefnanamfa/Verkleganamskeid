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

    topping.write(fout);
    fout.close();

}

vector<Topping> ToppingRepository::getToppings(){
    ifstream fin;
    vector<Topping> toppings;

    fin.open("topping.dat", ios::binary);
    while(!fin.eof()){
        Topping topping;

        topping.read(fin);

        if(fin.eof()){
            break;
        }
        toppings.push_back(topping);
    }

    fin.close();
    return toppings;
}

