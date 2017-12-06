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
        int salary;
        int month;
        int year;

    public:
        EmployeeSalary(string name, string id, int salary, int month, int year);

        friend istream& operator >>(istream& in, EmployeeSalary salary);
        friend ostream& operator <<(ostream& out, const EmployeeSalary salary);

        string getName() const;
        string getId() const;
        int getSalary() const;
        int getMonth() const;
        int getYear() const;

};

#endif // EMPLOYEESALARY_H
