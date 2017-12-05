#include "EmployeeSalaryRepository.h"

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
