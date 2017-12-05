#include "EmployeeSalary.h"

EmployeeSalary::EmployeeSalary(string name, string id, int salary, int month, int year)
{
    this->name = name;
    this->id = id;
    this->salary = salary;
    this->month = month;
    this->year = year;
}
string EmployeeSalary::getName()const {
    return this->name;
}

string EmployeeSalary::getId() const{
    return this->id;
}

int EmployeeSalary::getSalary() const{
    return this->salary;
}

int EmployeeSalary::getMonth() const{
    return this->month;
}

int EmployeeSalary::getYear() const{
    return this->year;
}

istream& operator >>(istream& in, EmployeeSalary salary){
    cout << "Name:   ";
    in >> ws;
    getline(in, salary.name);

    cout << "Id:     ";
    in >> salary.id;

    cout << "Salary: ";
    in >> salary.salary;

    cout << "Month:  ";
    in >> salary.month;

    cout << "Year:   ";
    in >> salary.year;
    return in;
}
ostream& operator <<(ostream& out, const EmployeeSalary salary){
    out << "Name:   " << salary.name << endl;
    out << "Id:     " << salary.id << endl;
    out << "Salary: " << salary.salary << endl;
    out << "Month:  " << salary.month << endl;
    out << "Year:   " << salary.year << endl;
    return out;
}
