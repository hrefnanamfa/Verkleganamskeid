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

    try {
        fout.open("topping.dat", ios::binary);
        if (fout.is_open()){
            for(unsigned int i = 0; i < toppings.size(); i++){
                toppings.at(i).write(fout);
            }
            fout.close();
        }
        else {
            throw InvalidWriteException();
        }
    }
    catch (InvalidWriteException){
        cout << "[UNABLE TO WRITE INTO FILE topping.dat]" << endl;
    }
}

void ToppingRepository::addTopping(Topping& topping){
    ofstream fout;

    try {
        fout.open("topping.dat", ios::binary|ios::app);
        if (fout.is_open()){
            topping.write(fout);
            fout.close();
        }
        else {
            throw InvalidReadException();
        }
    }
    catch (InvalidWriteException){
        cout << "[UNABLE TO WRITE INTO FILE topping.dat]" << endl;
    }
}

vector<Topping> ToppingRepository::getToppings(){
    ifstream fin;
    vector<Topping> toppings;

    try {
        fin.open("topping.dat", ios::binary);
        if (fin.is_open()){
            while(!fin.eof()){
                Topping topping;
                topping.read(fin);

                if(fin.eof())
                    break;
                toppings.push_back(topping);
            }

            fin.close();
        }
        else {
            throw InvalidReadException();
        }
    }
    catch (InvalidReadException){
        cout << "[UNABLE TO READ FILE topping.dat]" << endl;
    }
    return toppings;
}

