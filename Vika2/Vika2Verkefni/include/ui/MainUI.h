#ifndef MAINUI_H
#define MAINUI_H
#include <string>
#include <iostream>
#include "../services/EmployeeSalaryService.h"
#include "../exceptions/InvalidIdException.h"
#include "../exceptions/InvalidSalaryException.h"
#include "../exceptions/InvalidNameException.h"
#include "../exceptions/InvalidMonthException.h"
using namespace std;

class MainUI
{
    private:
        EmployeeSalaryService salary_service;

    public:
        MainUI();
        void startUI();
        virtual ~MainUI();
        EmployeeSalary create_salary();
};

#endif // MAINUI_H
