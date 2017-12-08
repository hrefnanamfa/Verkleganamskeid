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

        void add_salary(const EmployeeSalary& salary, string filename);
        void load_salary_file(string filename);
        string find_id(string id);
        int total_salary(string id, string year);
        string top_salary(string year);

        bool isValidId(string id);
        bool isValidSalary(string salarySTR, int salary);
        bool isValidName(string name);
        bool isValidMonth(int month);
        bool isValidYear(int year);
};

#endif // EMPLOYEESALARYSERVICE_H
