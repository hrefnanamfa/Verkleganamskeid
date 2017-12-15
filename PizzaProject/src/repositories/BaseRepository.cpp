#include "../../include/repositories/BaseRepository.h"

void BaseRepository::replaceBasesInRepo(vector<Base> bases){
    ofstream fout;

    try {
        fout.open("base.dat", ios::binary);
        if (fout.is_open()){
            for(unsigned int i = 0; i < bases.size(); i++){
                bases.at(i).write(fout);
            }
            fout.close();
        }
        else {
            throw InvalidWriteException();
        }
    }
    catch (InvalidWriteException){
        cout << "[UNABLE TO WRITE INTO FILE base.dat]" << endl;
    }
}

void BaseRepository::addBase(Base& base){
    ofstream fout;
    try {
        fout.open("base.dat", ios::binary|ios::app);
        if (fout.is_open()){
            base.write(fout);
            fout.close();
        }
        else {
            throw InvalidWriteException();
        }
    }
    catch (InvalidWriteException){
        cout << "[UNABLE TO WRITE INTO FILE base.dat]" << endl;
    }

}

vector<Base> BaseRepository::getBases() {
    ifstream fin;
    vector<Base> bases;

    try {
        fin.open("base.dat", ios::binary);
        if (fin.is_open()){
            while(!fin.eof()){
                Base base;

                base.read(fin);

                if(fin.eof())
                    break;
                bases.push_back(base);
            }
            fin.close();
        }
        else {
            throw InvalidReadException();
        }
    }
    catch (InvalidReadException){
        cout << "[UNABLE TO READ FILE base.dat]" << endl;
    }
    return bases;
}
