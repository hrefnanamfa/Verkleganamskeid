#include "../../include/ui/MainUI.h"
#include <cstdlib>

int const ID_SIZE = 10;
string const filename = "salaries.txt";

MainUI::MainUI()
{
    //ctor
}

MainUI::~MainUI()
{
    //dtor
}

void MainUI::startUI(){

    string id, year;
    char input = '\0';

    salary_service.load_salary_file(filename);

    do{
        cout << "Hello please pick an option: " << endl << endl;
        cout << "1. Add a salary record" << endl;
        cout << "2. Get all salary records for a given SSN" << endl;
        cout << "3. Get a total salary for a given SSN and a given year" << endl;
        cout << "4. Get the name of the employee with the highest total salary for a given year" << endl;
        cin >> input;

        if(input == '1'){
            salary_service.add_salary(create_salary(), filename);
        }
        else if(input == '2'){

            cout << "SSN: ";
            cin >> id;

            cout << salary_service.find_id(id) << endl;
        }
        else if(input == '3'){

            cout << "SSN: ";
            cin >> id;
            cout << "Year: ";
            cin >> year;

            cout << endl << "----- Total salary -----" << endl;
            cout << "----\t" << id << "  ----" << endl;
            cout << "----\t" << year << "\t    ----" << endl;
            cout << "---\t" << salary_service.total_salary(id, year) << "\t     ---" << endl << endl;

        }
        else if(input == '4'){
            cout << "Year: ";
            cin >> year;
            cout << endl << "Highest total salary for " << year << " is: " << salary_service.top_salary(year) << endl << endl;
        }

    }while(true);
}

EmployeeSalary MainUI::create_salary(){
    string name, id, salarySTR;
    int month, year, salary;
    bool allowed = false;

    do{
        try{
            cout << "Name:   ";
            cin >> ws;
            getline(cin, name);
            allowed = salary_service.isValidName(name);
        }
        catch (InvalidNameException){
            cout << "[Invalid name! The name should only contain letters from the alphabet]" << endl;
        }
    }while(!allowed);

    allowed = false;
    do{
        try{
            cout << "Id:     ";
            cin >> id;
            allowed = salary_service.isValidId(id);

            }
        catch (InvalidIdException){
            cout << "[Invalid Id! The id should contain 10 numbers]" << endl;
        }
    }while(!allowed);

    allowed = false;
    do{
        try{
            cout << "Salary: ";
            cin >> salarySTR;
            salary = atoi(salarySTR.c_str());
            allowed = salary_service.isValidSalary(salarySTR, salary);
        }
        catch (InvalidSalaryException){
            cout << "[Invalid salary! The salary can not be less than 0 and must contain only digits]" << endl;
        }
    }while(!allowed);

    allowed = false;
    do{
         try{
            cout << "Month:  ";
            cin >> month;
            allowed = salary_service.isValidMonth(month);
         }
         catch(InvalidMonthException){
            cout << "[Invalid month! The month should be a number from 1 to 12]" << endl;
         }
    }while(!allowed);

    allowed = false;
    do{
        try{
            cout << "Year:   ";
            cin >> year;
            allowed = salary_service.isValidYear(year);
        }
        catch(InvalidYearException){
            cout << "[Invalid year! The year is 2017]" << endl;
        }
    }while(!allowed);

    cout << endl;

    return EmployeeSalary(name, id, salary, month, year);
}


