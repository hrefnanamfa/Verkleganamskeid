#include "Base.h"

Base::Base()
{
    name = "";
    price = 0;
    verbose = true;
}

Base::~Base()
{
    //dtor
}
string Base::getName() const{
    return name;
}

double Base::getPrice() const{
    return price;
}

void Base::setName(string name){
    this->name = name;
}

void Base::setPrice(double price){
    this->price = price;
}

void Base::setVerbose(bool setting){
    this->verbose = setting;
}

ostream& operator << (ostream& out, const Base& base){
    out << base.getName();
    out << ",";
    out << base.getPrice();
    return out;
}

istream& operator >> (istream& in, Base& base){
    string name;
    int price;

    if(base.verbose){
        cout << "Base name: ";
    }
    in >> name;
    base.setName(name);

    if(base.verbose){
        cout << "Base price: ";
    }
    in >> price;
    base.setPrice(price);

    return in;
}
