#ifndef EMPLOYEESALARYSERVICE_H
#define EMPLOYEESALARYSERVICE_H
#include "../models/EmployeeSalary.h"
#include "../repositories/EmployeeSalaryRepository.h"
#include "../exceptions/InvalidIdException.h"
#include "../exceptions/InvalidSalaryException.h"
#include "../exceptions/InvalidNameException.h"
#include "../exceptions/InvalidMonthException.h"
#include "../exceptions/InvalidYearException.h"


class EmployeeSalaryService
{
    private:
        EmployeeSalaryRepository salary_repo;


    public:
        EmployeeSalaryService();
        virtual ~EmployeeSalaryService();

        void add_salary(const EmployeeSalary& salary);
        void load_salary_file(string filename);
        void find_id();

        bool isValidId(string id);
        bool isValidSalary(int salary);
        bool isValidName(string name);
        bool isValidMonth(int month);
        bool isValidYear(int year);
};

#endif // EMPLOYEESALARYSERVICE_H
