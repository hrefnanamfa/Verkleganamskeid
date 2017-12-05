#ifndef MAINUI_H
#define MAINUI_H
#include <string>
#include <iostream>
#include "EmployeeSalaryService.h"
#include "InvalidIdException.h"
#include "InvalidSalaryException.h"
#include "InvalidNameException.h"
#include "InvalidMonthException.h"
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
