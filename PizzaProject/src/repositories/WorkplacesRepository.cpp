#include "../../include/repositories/WorkplacesRepository.h"

WorkplacesRepository::WorkplacesRepository()
{
    //ctor
}

WorkplacesRepository::~WorkplacesRepository()
{
    //dtor
}
void WorkplacesRepository::replaceWorkplacesInRepo(vector<Workplaces> workplaces){
    ofstream fout;
    fout.open("workplaces.dat", ios::binary);

    for(unsigned int i = 0; i < workplaces.size(); i++){
        workplaces.at(i).write(fout);
    }
    fout.close();
}

void WorkplacesRepository::addWorkplace(Workplaces& workplaces){
    ofstream fout;

    fout.open("workplaces.dat", ios::binary|ios::app);

    workplaces.write(fout);
    fout.close();
}

vector<Workplaces> WorkplacesRepository::getWorkplaces() {
    ifstream fin;
    vector<Workplaces> workplaces;

    fin.open("workplaces.dat", ios::binary);

    while(!fin.eof()){
        Workplaces workplace;

        workplace.read(fin);

        if(fin.eof())
            break;
        workplaces.push_back(workplace);
    }

    fin.close();
    return workplaces;
}
