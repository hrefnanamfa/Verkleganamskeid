#include "WorkplacesUI.h"

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
    cout << "- Workplaces -" << endl;
    workplacesservice.listAvailableWorkplaces();
}
