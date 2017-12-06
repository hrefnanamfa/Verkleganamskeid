#include "Pizza.h"

Pizza::Pizza()
{
    //ctor
}

Pizza::~Pizza()
{
    //dtor
}

void Pizza::addTopping(Topping topping){
    toppings.push_back(topping);
}

void Pizza::setBase(Base base){
    this->base = base;
}
void Pizza::setPrice(double price){
    this->price = price;
}

void Pizza::write(ofstream& fout) const{
    int tCount = toppings.size();

    fout.write((char*)(&tCount), sizeof(int));

    for(int i = 0; i < tCount; i++){
        fout.write((char*)(&toppings.at(i)), sizeof(Topping));
    }
}

void Pizza::read(ifstream& fin){
    int tCount;
    fin.read((char*)(&tCount), sizeof(int));

    Topping topping;
    for(int i = 0; i < tCount; i++){
        fin.read((char*)(&toppings.at(i)), sizeof(Topping));
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
    out << pizza.base << ", ";
    for(unsigned int i = 0; i < pizza.toppings.size(); i++){
        out << pizza.toppings.at(i);
    }

    return out;
}
