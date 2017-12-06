#include "../../include/models/Topping.h"

Topping::Topping()
{
    name = "";
    price = 0;
    verbose = true;
}

Topping::~Topping()
{
    //dtor
}

void Topping::setName(string name){
    this->name = name;
}

void Topping::setPrice(double price){
    this->price = price;
}
string Topping::getName() const{
    return this->name;
}

double Topping::getPrice() const{
    return this->price;
}

void Topping::setVerbose(bool setting){
    this->verbose = setting;
}
void Topping::write(ofstream& fout) const{
    int stringLength = name.length() + 1;

    fout.write((char*)(&stringLength), sizeof(int));
    fout.write(name.c_str(), stringLength);

    fout.write((char*)(&price), sizeof(double));
}
void Topping::read(ifstream& fin){
    int stringLength;

    fin.read((char*)(&stringLength), sizeof(int));
    char *str = new char[stringLength];

    fin.read(str, stringLength);

    name = str;

    fin.read((char*)(&price), sizeof(double));
}

ostream& operator << (ostream& out, const Topping& topping){
    out << topping.getName();
    out << ",";
    out << topping.getPrice();
    return out;
}

istream& operator >> (istream& in, Topping& topping){

    if(topping.verbose){
        cout << "Topping name: ";
    }
    in >> ws;
    getline(in, topping.name);

    if(topping.verbose){
        cout << "Topping price: ";
    }

    in >> topping.price;

    return in;
}
