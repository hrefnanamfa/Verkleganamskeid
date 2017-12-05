#include "MainUI.h"
int const ID_SIZE = 10;


MainUI::MainUI()
{
    //ctor
}

MainUI::~MainUI()
{
    //dtor
}
void MainUI::startUI(){
    char input = '\0';

    do{
    cout << "Hello please pick an option: " << endl;
    cout << endl;
    cout << "1. Add a salary record" << endl;
    cout << "2. Get all salary records for a given SSN" << endl;
    cout << "3. Get a total salary for a given SSN and a given year" << endl;
    cout << "4. Get the name of the employee with the highest total salary for a given year" << endl;
    cin >> input;

    if(input == '1'){
        salary_service.add_salary(create_salary());
    }
    else if(input == '2'){

    }
    else if(input == '3'){

    }

    else if(input == '4'){

    }

    }while(true);
}

EmployeeSalary MainUI::create_salary(){
    string name;
    string id;
    int month, year;
    double salary;

    cout << "Name:   ";
    cin >> ws;
    getline(cin, name);
    cout << "Id:     ";

    cin >> id;
    while(!validateId(id)){
        cout << "[Invalid Id! Try again}" << endl;
        cout << "Id:     ";
        cin >> id;
    }

    cout << "Salary: ";
    cin >> salary;
    cout << "Month:  ";
    cin >> month;
    cout << "Year:   ";
    cin >> year;
    cout << endl;
    return EmployeeSalary(name, id, salary, month, year);
}

bool MainUI::validateId(string id){

}

