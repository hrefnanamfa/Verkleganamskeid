#include "../../include/repositories/EmployeeSalaryRepository.h"
#include <sstream>
#include <stdlib.h>
#include <string>
#include <algorithm>

EmployeeSalaryRepository::EmployeeSalaryRepository()
{
    //ctor
}

EmployeeSalaryRepository::~EmployeeSalaryRepository()
{
    //dtor
}

void EmployeeSalaryRepository::write_file(string filename){
    try {
        ofstream fout;

        fout.open(filename.c_str());

        string filestring = "";

        for (int i = 0; i < salaries.size(); i++) {
            filestring += salaries[i] + ",";
        }
        if(fout.is_open()){
            fout << filestring;
            fout.close();
        } else {
            throw InvalidWriteException();
        }
    }
    catch (InvalidWriteException) {
        cout << "[File write ERROR]" << endl;
        exit(0);
    }
}

void EmployeeSalaryRepository::add_salary(const EmployeeSalary& salary, string filename){
    bool exists = false;

    ostringstream s;

    s << salary.getSalary();
    string slry = s.str();
    s.str("");

    s << salary.getMonth();
    string mth = s.str();
    s.str("");

    s << salary.getYear();
    string yr = s.str();

    for (int i = 1; i < salaries.size(); i += 5){
        if (salary.getId() == salaries[i]){
            if (salary.getYear() == atoi((salaries[i+3]).c_str()) && salary.getMonth() == atoi((salaries[i+2]).c_str())) {
                cout << "Entry already exists, overwriting.." << endl;
                salaries[i+1] = slry;
                exists = true;
            }
        }
    }

    if (!exists){
        salaries.push_back(salary.getName());
        salaries.push_back(salary.getId());
        salaries.push_back(slry);
        salaries.push_back(mth);
        salaries.push_back(yr);
    }

    write_file(filename);
}

void EmployeeSalaryRepository::load_salaries(string filename){
    try {
        ifstream fin;
        fin.open(filename.c_str());

        if (fin.is_open()) {
            while (!fin.eof()){
                fin >> file;
            }
            fin.close();
        } else {
            throw InvalidReadException();
        }

        stringstream ss(file);
        string item;

        while(getline(ss, item, ',')){
            salaries.push_back(item);
        }

    }
    catch (InvalidReadException) {
        cout << "[File read ERROR]" << endl;
        exit(0);
    }
}

string EmployeeSalaryRepository::find_id(string id){
    string output = "";

    for (int i = 1; i < salaries.size(); i += 5){
        if (id == salaries[i]) {
            output += salaries[i-1] + ", " + salaries[i] +  ", " + salaries[i + 1] +  ", " + salaries[i + 2] +  ", " + salaries[i + 3];
        }
        output += "\n";
    }
    return output;
}

int EmployeeSalaryRepository::total_salary(string id, string year){
    int salary = 0, x;
    for (int i = 1; i < salaries.size(); i += 5){
        if (id == salaries[i] && year == salaries[i+3]) {
            x = atoi(salaries[i+1].c_str());
            salary += x;
        }
    }
    return salary;
}

string EmployeeSalaryRepository::top_salary(string year){
    vector<string> SSN;
    int maxpos;
    string name = "";

    for (int i = 1; i < salaries.size(); i += 5){                       // For lykkja keyrir í gegnum kennitölur á öllum records
        if (!(binary_search(SSN.begin(), SSN.end(), salaries[i]))){     // binary_search athugar hvort kennitalan var núþegar skráð
            SSN.push_back(salaries[i]);                                 // Ef ekki, þá er kennitölunni bætt við vectorinn SSN
        }                                                               // SSN inniheldur þá allar _UNIQUE_ kennitölur
    }

    int salary[SSN.size()];                                             // Hliðstæður array salary heldur utanum laun fyrir hverja kennitölu í SSN

    for (int i = 0; i < SSN.size(); i++){
        salary[i] = 0;
        for (int j = 1; j < salaries.size(); j += 5) {                  // Leita í gegnum kennitölur úr öllum records og bæti launum við heildartölu
            if (SSN[i] == salaries[j]) {                                // í salary array.
                salary[i] += atoi(salaries[j+1].c_str());               // Kennitala í staki 0 í SSN hefur þá heildarlaun í sama staki (0) í salary array
            }
        }
    }

    for (int i = 1; i < SSN.size(); i++){                               // Finn staðsetningu í array á hæstu heildarlaunum
        if (salary[i] > salary[i-1])                                    // Staðsetning jafngildir staðsetningu kennitölu
            maxpos = i;
        else
            maxpos = i-1;
    }

    for (int i = 1; i < salaries.size(); i += 5){                       // Nafn fundið á kennitölunni með hæstu heildarlaunin skilað
        if (SSN[maxpos] == salaries[i])
            name = salaries[i-1];
    }

    return name;
}
