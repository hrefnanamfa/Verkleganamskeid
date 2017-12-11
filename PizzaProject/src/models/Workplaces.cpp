#include "Workplaces.h"

Workplaces::Workplaces(){
    name = "";
}

Workplaces::~Workplaces(){
    //dtor
}

string Workplaces::getName() const{
    return name;
}

void Workplaces::setName(string name){
    this->name = name;
}

void Workplaces::write(ofstream& fout) const{
    int stringLength = name.length() + 1;

    fout.write((char*)(&stringLength), sizeof(int));
    fout.write(name.c_str(), stringLength);
}

void Workplaces::read(ifstream& fin){
    int stringLength;

    fin.read((char*)(&stringLength), sizeof(int));
    char *str = new char[stringLength];

    fin.read(str, stringLength);

    name = str;
}

ostream& operator << (ostream& out, const Workplaces& workplaces){
    out << workplaces.getName();
    return out;
}

istream& operator >> (istream& in, Workplaces& workplaces){
    if(workplaces.verbose){
        cout << "Workplace name: ";
    }
    in >> ws;
    getline(in, workplaces.name);
    return in;
}
