#include "../../include/repositories/PizzaRepository.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

PizzaRepository::~PizzaRepository()
{
    //dtor
}
void PizzaRepository::addPizzaToRepo(const Pizza& pizza){
    ofstream fout;
    fout.open("pizza.dat", ios::binary|ios::app);

    pizza.write(fout);

    fout.close();
}

vector<Pizza> PizzaRepository::getPizzas(){
    ifstream fin;
    vector<Pizza> pizzas;

    fin.open("pizza.dat", ios::binary);

    Pizza pizza;

    while(!fin.eof()){
        pizza.read(fin);

        if(fin.eof()){
            break;
        }
        pizzas.push_back(pizza);
    }
    fin.close();
    return pizzas;
}
