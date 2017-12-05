#ifndef MAINUI_H
#define MAINUI_H
#include <string>
#include <iostream>
#include "EmployeeSalaryService.h"
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
        bool validateId(string id);
};

#endif // MAINUI_H
