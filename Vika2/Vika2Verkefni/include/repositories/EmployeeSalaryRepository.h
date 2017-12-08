#ifndef EMPLOYEESALARYREPOSITORY_H
#define EMPLOYEESALARYREPOSITORY_H
#include "../models/EmployeeSalary.h"
#include <fstream>
#include <vector>
#include "../exceptions/InvalidReadException.h"
#include "../exceptions/InvalidWriteException.h"

class EmployeeSalaryRepository
{
    private:
        string file;
        vector<string> salaries;

    public:
        EmployeeSalaryRepository();
        virtual ~EmployeeSalaryRepository();

        void write_file(string filename);
        void add_salary(const EmployeeSalary& salary, string filename);
        void load_salaries(string filename);
        string find_id(string id);
        int total_salary(string id, string year);
        string top_salary(string year);
};

#endif // EMPLOYEESALARYREPOSITORY_H
