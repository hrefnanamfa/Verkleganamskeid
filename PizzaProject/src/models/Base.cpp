#include "../../include/models/Base.h"

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

int Base::getPrice() const{
    return price;
}

void Base::setName(string name){
    this->name = name;
}

void Base::setPrice(int price){
    this->price = price;
}

void Base::setVerbose(bool setting){
    this->verbose = setting;
}

void Base::write(ofstream& fout) const{
    int stringLength = name.length() + 1;

    fout.write((char*)(&stringLength), sizeof(int));
    fout.write(name.c_str(), stringLength);

    fout.write((char*)(&price), sizeof(int));
}

void Base::read(ifstream& fin){
    int stringLength;

    fin.read((char*)(&stringLength), sizeof(int));
    char *str = new char[stringLength];

    fin.read(str, stringLength);

    name = str;

    fin.read((char*)(&price), sizeof(int));
}

ostream& operator << (ostream& out, const Base& base){
    out << base.getName();
    if (base.getName().length() > 10)
        out << "\t";
    else
        out << "  \t\t";
    out << base.getPrice() << " kr.";
    return out;
}

istream& operator >> (istream& in, Base& base){
    //string name;
    //int price;

    if(base.verbose){
        cout << "Base name: ";
    }
    in >> ws;
    getline(in, base.name);
    //in >> name;
    //base.setName(name);

    if(base.verbose){
        cout << "Base price: ";
    }
    in >> base.price;
    //base.setPrice(price);

    return in;
}
