#ifndef EMPLOYEESALARYSERVICE_H
#define EMPLOYEESALARYSERVICE_H
#include "EmployeeSalary.h"
#include "EmployeeSalaryRepository.h"
#include "InvalidIdException.h"
#include "InvalidSalaryException.h"
#include "InvalidNameException.h"
#include "InvalidMonthException.h"
#include "InvalidYearException.h"


class EmployeeSalaryService
{
    private:
        EmployeeSalaryRepository salary_repo;


    public:
        EmployeeSalaryService();
        void add_salary(const EmployeeSalary& salary);
        virtual ~EmployeeSalaryService();
        bool isValidId(string id);
        bool isValidSalary(int salary);
        bool isValidName(string name);
        bool isValidMonth(int month);
        bool isValidYear(int year);
};

#endif // EMPLOYEESALARYSERVICE_H
