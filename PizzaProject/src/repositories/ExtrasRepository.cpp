#include "../../include/repositories/ExtrasRepository.h"

void ExtrasRepository::replaceExtrasInRepo(vector<Extras> extras){
    ofstream fout;
    try {
        fout.open("extras.dat", ios::binary);
        if (fout.is_open()){
            for(unsigned int i = 0; i < extras.size(); i++){
                extras.at(i).write(fout);
            }
            fout.close();
        }
        else {
            throw InvalidWriteException();
        }
    }
    catch (InvalidWriteException){
        cout << "[UNABLE TO WRITE INTO FILE extras.dat]" << endl;
    }
}

void ExtrasRepository::addExtras(Extras& extras){
    ofstream fout;

    try {
        fout.open("extras.dat", ios::binary|ios::app);
        if (fout.is_open()){
            extras.write(fout);
            fout.close();
        }
        else {
            throw InvalidWriteException();
        }
    }
    catch (InvalidWriteException){
        cout << "[UNABLE TO WRITE INTO FILE extras.dat]" << endl;
    }
}

vector<Extras> ExtrasRepository::getExtras(){
    ifstream fin;
    vector<Extras> extras;

    try {
        fin.open("extras.dat", ios::binary);
        if (fin.is_open()){

            while(!fin.eof()){
                Extras extra;
                extra.read(fin);

                if(fin.eof())
                    break;
                extras.push_back(extra);
            }

            fin.close();
        }
        else {
            throw InvalidReadException();
        }
    }
    catch (InvalidReadException){
        cout << "[UNABLE TO READ FILE extras.dat]" << endl;
    }
    return extras;
}

