#include "../../include/repositories/PizzaRepository.h"

void PizzaRepository::replacePizzasInRepo(vector<Pizza> pizzas){
    ofstream fout;
    try {
        fout.open("pizza.dat", ios::binary);
        if (fout.is_open()){
            for(unsigned int i = 0; i < pizzas.size(); i++){
                pizzas.at(i).write(fout);
            }
            fout.close();
        }
        else {
            throw InvalidWriteException();
        }
    }
    catch (InvalidWriteException){
        cout << "[UNABLE TO WRITE INTO FILE pizza.dat]" << endl;
    }
}

void PizzaRepository::addPizzaToRepo(const Pizza& pizza){
    ofstream fout;
    try {
        fout.open("pizza.dat", ios::binary|ios::app);
        if (fout.is_open()){
            pizza.write(fout);
            fout.close();
        }
        else {
            throw InvalidReadException();
        }
    }
    catch (InvalidWriteException){
        cout << "[UNABLE TO WRITE INTO FILE pizza.dat]" << endl;
    }
}

vector<Pizza> PizzaRepository::getPizzas(){
    ifstream fin;

    vector<Pizza> pizzas;

    try {
        fin.open("pizza.dat", ios::binary);
        if (fin.is_open()){
            while(!fin.eof()){
                Pizza pizza;
                pizza.read(fin);

                if(fin.eof()){
                    break;
                }
                pizzas.push_back(pizza);
            }
            fin.close();
        }
        else {
            throw InvalidReadException();
        }
    }
    catch (InvalidReadException){
        cout << "[UNABLE TO READ FILE pizza.dat]" << endl;
    }
    return pizzas;
}
