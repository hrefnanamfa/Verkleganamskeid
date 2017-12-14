#include "../../include/repositories/ExtrasRepository.h"

ExtrasRepository::ExtrasRepository()
{
    //ctor
}

ExtrasRepository::~ExtrasRepository()
{
    //dtor
}

void ExtrasRepository::replaceExtrasInRepo(vector<Extras> extras){
    ofstream fout;
    fout.open("extras.dat", ios::binary);

    for(unsigned int i = 0; i < extras.size(); i++){
        extras.at(i).write(fout);
    }
    fout.close();
}

void ExtrasRepository::addExtras(Extras& extras){
    ofstream fout;

    fout.open("extras.dat", ios::binary|ios::app);

    extras.write(fout);
    fout.close();

}

vector<Extras> ExtrasRepository::getExtras(){
    ifstream fin;
    vector<Extras> extras;

    fin.open("extras.dat", ios::binary);


    while(!fin.eof()){
        Extras extra;
        extra.read(fin);

        if(fin.eof())
            break;
        extras.push_back(extra);
    }

    fin.close();
    return extras;
}

