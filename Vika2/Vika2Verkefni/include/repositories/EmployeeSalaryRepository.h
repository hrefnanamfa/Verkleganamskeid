#ifndef EMPLOYEESALARYREPOSITORY_H
#define EMPLOYEESALARYREPOSITORY_H
#include "../models/EmployeeSalary.h"
#include <fstream>
#include <vector>

class EmployeeSalaryRepository
{
    private:
        string salaries;
        vector<string> split;

    public:
        EmployeeSalaryRepository();
        virtual ~EmployeeSalaryRepository();

        void add_salary(const EmployeeSalary& salary);
        void load_salaries(string filename);
        void find_id(int id);
};

#endif // EMPLOYEESALARYREPOSITORY_H
