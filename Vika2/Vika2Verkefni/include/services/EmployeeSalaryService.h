#ifndef EMPLOYEESALARYSERVICE_H
#define EMPLOYEESALARYSERVICE_H
#include "EmployeeSalary.h"
#include "EmployeeSalaryRepository.h"



class EmployeeSalaryService
{
    private:
        EmployeeSalaryRepository salary_repo;

    public:
        EmployeeSalaryService();
        void add_salary(const EmployeeSalary& salary);

        virtual ~EmployeeSalaryService();

};

#endif // EMPLOYEESALARYSERVICE_H
