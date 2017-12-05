#ifndef EMPLOYEESALARYREPOSITORY_H
#define EMPLOYEESALARYREPOSITORY_H
#include "EmployeeSalary.h"
#include <fstream>

class EmployeeSalaryRepository
{
    private:

    public:
        EmployeeSalaryRepository();
        void add_salary(const EmployeeSalary& salary);
        virtual ~EmployeeSalaryRepository();
};

#endif // EMPLOYEESALARYREPOSITORY_H
