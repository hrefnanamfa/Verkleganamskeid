#include "BaseRepository.h"

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

    fout.open("base.txt", ios::app);

    base.setVerbose(false);

    if(fout.is_open()){
        fout << base << endl;
        fout.close();
    }
    else{
        cout << "file not open" << endl;
    }
    cout << endl;
}
