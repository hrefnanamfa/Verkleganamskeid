#include "../../include/repositories/BaseRepository.h"

BaseRepository::BaseRepository()
{
    //ctor
}

BaseRepository::~BaseRepository()
{
    //dtor
}

void BaseRepository::addBase(Base& base){
    ofstream fout;

    // ---- Binary vistun ----
    fout.open("base.dat", ios::binary|ios::app);

    base.write(fout);
    fout.close();

    // ---- TXT vistun ----
    /*fout.open("base.txt", ios::app);

    base.setVerbose(false);

    if(fout.is_open()){
        fout << base << endl;
        fout.close();
    }
    else{
        cout << "file not open" << endl;
    }
    cout << endl;*/
}

vector<Base> BaseRepository::getBases() {
    ifstream fin;
    vector<Base> bases;

    fin.open("base.dat", ios::binary);
    Base base;

    while(!fin.eof()){

        base.read(fin);

        if(fin.eof())
            break;
        bases.push_back(base);
    }

    fin.close();
    return bases;
}
