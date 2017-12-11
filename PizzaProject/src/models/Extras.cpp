#include "./../include/models/Extras.h"

Extras::Extras()
{
    name = "";
    price = 0;
    verbose = true;
}


Extras::~Extras()
{
    //dtor
}

int Extras::getPriceOfExtras(){
    int priceOfExtras = getPrice();

    setPrice(priceOfExtras);
    return priceOfExtras;
}

void Extras::setName(string name){
    this->name = name;
}

void Extras::setPrice(int price){
    this->price = price;
}

string Extras::getName() const{
    return this->name;
}

int Extras::getPrice() const{
    return this->price;

}void Extras::setVerbose(bool setting){
    this->verbose = setting;
}

void Extras::write(ofstream& fout) const{
    int stringLength = name.length() + 1;

    fout.write((char*)(&stringLength), sizeof(int));
    fout.write(name.c_str(), stringLength);

    fout.write((char*)(&price), sizeof(int));
}

void Extras::read(ifstream& fin){
    int stringLength;

    fin.read((char*)(&stringLength), sizeof(int));
    char *str = new char[stringLength];

    fin.read(str, stringLength);

    name = str;

    fin.read((char*)(&price), sizeof(int));
}

ostream& operator << (ostream& out, const Extras& extras){

    out << extras.getName();
    out << ", ";
    out << extras.getPrice() << " kr.";
    return out;
}

istream& operator >> (istream& in, Extras& extras){

    if(extras.verbose){
        cout << "Extra item name: ";
    }
    in >> ws;
    getline(in, extras.name);

    if(extras.verbose){
        cout << extras.name << " price: ";
    }
    in >> extras.price;

    return in;
}
