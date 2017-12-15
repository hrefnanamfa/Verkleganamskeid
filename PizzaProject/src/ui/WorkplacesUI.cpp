#include "../../include/ui/WorkplacesUI.h"

WorkplacesUI::WorkplacesUI()
{
    //ctor
}

WorkplacesUI::~WorkplacesUI()
{
    //dtor
}

void WorkplacesUI::startUI(){
    char selection = '\n';
    while (selection != 'Q'){
        cout << "1. Add a workplace" << endl;
        cout << "2. Edit a workplace" << endl;
        cout << "3. Delete a workplace" << endl;
        cout << "4. View all workplaces" << endl << endl;
        cout << "q. to go back" << endl;

        cin >> selection;
        selection = toupper(selection);
        if (selection == '1'){
            addWorkplace();
        }
        else if (selection == '2'){
            string input;
            int select;
            bool workplacesempty;
            do{
                listWorkplaces();
                workplacesempty = workplaces.empty();
                if (!workplacesempty){
                    cout << "Select a workplace to edit" << endl;
                    cin >> input;
                    select = inputSanitize(input, (int)workplaces.size() + 1);
                }

            }while(select < 0);
            if (!workplacesempty) {
                Workplaces workplace;
                cin >> workplace;
                workplacesservice.replaceAndSaveWorkplaceAt(select - 1, workplace);
            }
        }
        else if (selection == '3'){
            string input;
            int select;
            bool workplacesempty;
            do{
                listWorkplaces();
                workplacesempty = workplaces.empty();
                if(!workplacesempty){
                    cout << "Select a workplace to delete" << endl;
                    cin >> input;
                    select = inputSanitize(input, (int)workplaces.size() + 1);
                }

            }while(select < 0);
            if (!workplacesempty) {
                    workplacesservice.deleteWorkplaceAtAndSave(select - 1);
            }
        }
        else if (selection == '4'){
            listWorkplaces();
        }
        cout << endl;
    }
}
bool WorkplacesUI::isWorkplacesVectorEmpty(){
    workplaces = workplacesservice.listAvailableWorkplaces();
    if(workplaces.empty()){
        cout << "There are no workplaces registered!" << endl << endl;
        return true;
    }
    else{
        return false;
    }
}

void WorkplacesUI::addWorkplace(){
    Workplaces workplaces;
    cout << "Adding a workplace" << endl;
    cin >> workplaces;
    workplacesservice.addWorkplace(workplaces);
}

void WorkplacesUI::listWorkplaces(){
    workplaces = workplacesservice.listAvailableWorkplaces();
    if(!workplaces.empty()){
        cout << "- Workplaces -" << endl;
        for(unsigned int i = 0; i < workplaces.size(); i++){
            cout << i + 1 << ". " << workplaces[i] << endl;
        }
    }
    else{
        cout << "There are no workplaces registered!" << endl << endl;

    }
}

Workplaces WorkplacesUI::selectWorkplace(){
    Workplaces workplace;
    string workChoice = "";
    int workMax, workChoiceInt;
    bool flag = true;

    workMax = workplacesservice.workplacesAmount();

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



int WorkplacesUI::inputSanitize(string input, int maxSize) {
    int select;
    if (isdigit(input[0])){
        select = atoi(input.c_str());
        if (select >  0 && select < maxSize) {
            return select;
        }
        else {
            cout << "Selection does not exist!" << endl << endl;
            return -1;
        }
    }
    else {
        cout << "Invalid input!" << endl;
        return -1;
    }
}
