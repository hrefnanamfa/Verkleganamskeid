#include "../../include/services/EmployeeSalaryService.h"

int const ID_SIZE = 10;

EmployeeSalaryService::EmployeeSalaryService()
{
    //ctor
}

EmployeeSalaryService::~EmployeeSalaryService()
{
    //dtor
}
void EmployeeSalaryService::add_salary(const EmployeeSalary& salary, string filename){
    salary_repo.add_salary(salary, filename);
}

void EmployeeSalaryService::load_salary_file(string filename){
    salary_repo.load_salaries(filename);
}

string EmployeeSalaryService::find_id(string id){
    return salary_repo.find_id(id);
}

int EmployeeSalaryService::total_salary(string id, string year){
    return salary_repo.total_salary(id, year);
}

string EmployeeSalaryService::top_salary(string year){
    return salary_repo.top_salary(year);
}

bool EmployeeSalaryService::isValidId(string id){
    for(unsigned int i = 0; i < id.length(); i++){
        if(isalpha(id[i]) || id.length() != ID_SIZE){
            throw InvalidIdException();
        }
    }
    return true;
}

bool EmployeeSalaryService::isValidSalary(int salary){
    if(salary < 0){
        throw InvalidSalaryException();
    }
    return true;
}

bool EmployeeSalaryService::isValidName(string name){
    for(unsigned int i = 0; i < name.length(); i++){
        if(!isalpha(name[i])){
            throw InvalidNameException();
        }
    }
    return true;
}
bool EmployeeSalaryService::isValidMonth(int month){
    if(month <= 0 || month > 12){
        throw InvalidMonthException();
    }
    return true;
}

bool EmployeeSalaryService::isValidYear(int year){
    if(year != 2017){
        throw InvalidYearException();
    }
    return true;
}


