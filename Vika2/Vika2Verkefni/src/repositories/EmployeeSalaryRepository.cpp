#include "../../include/repositories/EmployeeSalaryRepository.h"
#include <sstream>

EmployeeSalaryRepository::EmployeeSalaryRepository()
{
    //ctor
}

EmployeeSalaryRepository::~EmployeeSalaryRepository()
{
    //dtor
}

void EmployeeSalaryRepository::add_salary(const EmployeeSalary& salary){
    ofstream fout;

    fout.open("salaries.txt", ios:: app);
    if(fout.is_open()){
        fout << salary;
        fout.close();
    }
    else{
        cout << "Not open" << endl;
    }
}

void EmployeeSalaryRepository::load_salaries(string filename) {
    ifstream fin;
    fin.open(filename.c_str());

    if (fin.is_open()) {
        while (!fin.eof()){
            fin >> salaries;
        }
        fin.close();
    }

    stringstream ss(salaries);

    string item;
    while(getline(ss, item, ',')){
        split.push_back(item);
    }

    /*
    for (int i = 0; i < split.size(); i++) {
        cout << split[i] << ":";
    }
    for (int i = 0; i < salaries.length(); i++) {
        if (salaries[i] == ',') {
            split.push_back(i);
        }
    }
    for (int i = 0; i < split.size(); i++) {
        cout << split[i] << ":";
    }*/
}

void EmployeeSalaryRepository::find_id(int id) {
    int x;
    for (int i = 1; i < split.size(); i++) {
        //x = split[i];
        //cout << salaries[x];
    }
}
