#include "../../include/repositories/ToppingRepository.h"

ToppingRepository::ToppingRepository()
{
    //ctor
}

ToppingRepository::~ToppingRepository()
{
    //dtor
}

void ToppingRepository::replaceToppingsInRepo(vector<Topping> toppings){
    ofstream fout;

    fout.open("topping.dat", ios::binary);

    for(unsigned int i = 0; i < toppings.size(); i++){
        toppings.at(i).write(fout);
    }
    fout.close();
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

        if(fin.eof())
            break;
        toppings.push_back(topping);
    }

    fin.close();
    return toppings;
}

