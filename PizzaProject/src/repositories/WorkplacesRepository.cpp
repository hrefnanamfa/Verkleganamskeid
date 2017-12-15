#include "../../include/repositories/WorkplacesRepository.h"

void WorkplacesRepository::replaceWorkplacesInRepo(vector<Workplaces> workplaces){
    ofstream fout;
    try {
        fout.open("workplaces.dat", ios::binary);
        if (fout.is_open()){
            for(unsigned int i = 0; i < workplaces.size(); i++){
                workplaces.at(i).write(fout);
            }
            fout.close();
        }
        else {
            throw InvalidWriteException();
        }
    }
    catch (InvalidWriteException){
        cout << "[UNABLE TO WRITE INTO FILE workplaces.dat]" << endl;
    }
}

void WorkplacesRepository::addWorkplace(Workplaces& workplaces){
    ofstream fout;
    try {
        fout.open("workplaces.dat", ios::binary|ios::app);
        if (fout.is_open()){
            workplaces.write(fout);
            fout.close();
        }
        else {
            throw InvalidWriteException();
        }
    }
    catch (InvalidWriteException){
        cout << "[UNABLE TO WRITE INTO FILE workplaces.dat]" << endl;
    }
}

vector<Workplaces> WorkplacesRepository::getWorkplaces() {
    ifstream fin;
    vector<Workplaces> workplaces;
    try {
        fin.open("workplaces.dat", ios::binary);
        if (fin.is_open()){
            while(!fin.eof()){
                Workplaces workplace;

                workplace.read(fin);

                if(fin.eof())
                    break;
                workplaces.push_back(workplace);
            }
            fin.close();
        }
        else {
            throw InvalidReadException();
        }
    }
    catch (InvalidReadException){
        cout << "[UNABLE TO READ FILE workplaces.dat]" << endl;
    }

    return workplaces;
}
