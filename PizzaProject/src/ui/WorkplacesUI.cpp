#include "../../include/ui/WorkplacesUI.h"
#include "InvalidAnswerException.h"
#include <cstdlib>

WorkplacesUI::WorkplacesUI()
{
    //ctor
}

WorkplacesUI::~WorkplacesUI()
{
    //dtor
}

void WorkplacesUI::addWorkplace(){
    Workplaces workplaces;
    cout << "Adding a workplace" << endl;
    cin >> workplaces;

    workplacesservice.addWorkplace(workplaces);
}

void WorkplacesUI::listWorkplaces(){

    workplacesservice.listAvailableWorkplaces();
}

Workplaces WorkplacesUI::selectWorkplace(){
    Workplaces workplace;
    string workChoice = "";
    int workMax, workChoiceInt;
    bool flag = true;

    workMax = workplacesservice.workplacesAmount();

    cout << "Choose your workplace" << endl;
    listWorkplaces();

    do{
        try{
            cin >> workChoice;
            workChoiceInt = atoi(workChoice.c_str());
            if (workChoiceInt < 1 || workChoiceInt > workMax)
                throw InvalidAnswerException();
            flag = true;
        }
        catch(InvalidAnswerException){
            flag = false;
            cout << "Invalid workplace!" << endl;
        }

    }while(!flag);

    workplace = workplacesservice.getWorkplaceAt(workChoiceInt - 1);

    return workplace;
}
