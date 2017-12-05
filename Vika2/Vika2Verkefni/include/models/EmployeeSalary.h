#ifndef EMPLOYEESALARY_H
#define EMPLOYEESALARY_H
#include <string>
#include <iostream>

using namespace std;

class EmployeeSalary
{
    private:
        string name;
        string id;
        double salary;
        int month;
        int year;

    public:
        EmployeeSalary(string name, string id, double salary, int month, int year);
        friend istream& operator >>(istream& in, EmployeeSalary salary);
        friend ostream& operator <<(ostream& out, const EmployeeSalary salary);

        virtual ~EmployeeSalary();

};

#endif // EMPLOYEESALARY_H
