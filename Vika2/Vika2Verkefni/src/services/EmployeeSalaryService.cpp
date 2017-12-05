#include "EmployeeSalaryService.h"

EmployeeSalaryService::EmployeeSalaryService()
{
    //ctor
}

EmployeeSalaryService::~EmployeeSalaryService()
{
    //dtor
}
void EmployeeSalaryService::add_salary(const EmployeeSalary& salary){
    salary_repo.add_salary(salary);
}
