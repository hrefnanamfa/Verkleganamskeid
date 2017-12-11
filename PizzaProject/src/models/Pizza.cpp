#include "../../include/models/Pizza.h"

Pizza::Pizza()
{
    //ctor
}

Pizza::~Pizza()
{
    //dtor
}

int Pizza::getPriceOfPizza(){
    int priceOfBase = base.getPrice();
    int priceOfToppings = 0;
    int PriceOfPizza = 0;

    for(unsigned int i = 0; i < toppings.size(); i++){
        priceOfToppings += toppings.at(i).getPrice();
    }
    PriceOfPizza = priceOfBase + priceOfToppings;

    setPrice(PriceOfPizza);
    return PriceOfPizza;
}

void Pizza::addTopping(const Topping& topping){
    toppings.push_back(topping);
}

void Pizza::setToppings(vector<Topping> toppings){
    this->toppings = toppings;
}


void Pizza::setBase(const Base& base){
    this->base = base;
}

void Pizza::setPrice(int price){
    this->price = price;
}

void Pizza::write(ofstream& fout) const{
    base.write(fout);

    int count_toppings = toppings.size();
    fout.write((char*)(&count_toppings), sizeof(int));

    for (int i = 0; i < count_toppings; i++)
    {
        toppings[i].write(fout);
    }

}

void Pizza::read(ifstream& fin){
    Base base;
    base.read(fin);
    setBase(base);

    int count_toppings = 0;
    fin.read((char*)(&count_toppings), sizeof(int));

    for (int i = 0; i < count_toppings; i++)
    {
        Topping topping;
        topping.read(fin);
        addTopping(topping);
    }
}


istream& operator >> (istream& in, Pizza& pizza){
    cout << "What kind of base?" << endl;
    cin >> pizza.base;
    cout << "How many toppings?" << endl;
    int toppingCount;
    in >> toppingCount;

    Topping topping;
    for (unsigned int i = 0; i < pizza.toppings.size(); i++) {
        in >> topping;
        pizza.addTopping(topping);
    }
    return in;
}

ostream& operator << (ostream& out, Pizza& pizza){
    out << pizza.base.getName() << " base, ";
    for(unsigned int i = 0; i < pizza.toppings.size(); i++){
        out << pizza.toppings.at(i).getName() << ", ";
    }
    out << pizza.getPriceOfPizza() << "kr.";

    return out;
}
