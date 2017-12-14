#include "../../include/repositories/PizzaRepository.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

PizzaRepository::~PizzaRepository()
{
    //dtor
}
void PizzaRepository::replacePizzasInRepo(vector<Pizza> pizzas){
    ofstream fout;
    fout.open("pizza.dat", ios::binary);

    for(unsigned int i = 0; i < pizzas.size(); i++){
        pizzas.at(i).write(fout);
    }
    fout.close();
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


    while(!fin.eof()){
        Pizza pizza;
        pizza.read(fin);

        if(fin.eof()){
            break;
        }
        pizzas.push_back(pizza);
    }
    fin.close();
    return pizzas;
}
