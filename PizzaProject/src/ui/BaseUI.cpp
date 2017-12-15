#include "../../include/ui/BaseUI.h"

BaseUI::BaseUI()
{
    //ctor
}

BaseUI::~BaseUI()
{
    //dtor
}
void BaseUI::startUI(){
 char selection = '\n';
    while (selection != 'Q'){
        cout << "1. Add a base" << endl;
        cout << "2. Edit a base" << endl;
        cout << "3. Delete a base" << endl;
        cout << "4. View all bases" << endl << endl;
        cout << "q. to go back" << endl;

        cin >> selection;
        selection = toupper(selection);
        if (selection == '1'){
            createBase();
        }
        else if (selection == '2'){
            string input;
            int select = 0;
            bool basesempty;
            do{
                listBases();
                basesempty = bases.empty();
                if(!basesempty){
                    cout << "Select a base to edit" << endl;
                    cin >> input;
                    select = inputSanitize(input, (int)bases.size() + 1);
                }
            }while(select < 0);
            if (!basesempty) {
                Base base;
                cin >> base;
                baseservice.replaceAndSaveBaseAt(select - 1, base);
            }
        }
        else if (selection == '3'){
            string input;
            int select = 0;
            bool basesempty;
            do{
                listBases();
                basesempty = bases.empty();
                if(!basesempty){
                    cout << "Select a base to delete" << endl;
                    cin >> input;

                    select = inputSanitize(input, (int)bases.size() + 1);
                }
            }while(select < 0);
            if (!basesempty) {
                baseservice.deleteBaseAtAndSave(select);
            }
        }
        else if (selection == '4'){
            listBases();
        }
        cout << endl;
    }
}

void BaseUI::createBase(){
    Base base;
    cin >> base;
    baseservice.addBase(base);
}

bool BaseUI::isBaseVectorEmpty(){
    bases = baseservice.listAvailableBases();
    if(bases.empty()){
        return true;
    }
    else{
        return false;
    }
}

int BaseUI::getBaseVectorSize(){
    return this->bases.size();
}

void BaseUI::listBases() {
    cout << "- Bases -" << endl;
    bases = baseservice.listAvailableBases();

    if(!bases.empty()){
        for(unsigned int i = 0; i < bases.size(); i++){
            cout << i + 1 << ". " << bases[i] << endl;
        }
    }
    else if(bases.empty()){
        cout << "There are no bases registered!" << endl;
    }
}


int BaseUI::inputSanitize(string input, int maxSize) {
    int select;
    if (isdigit(input[0])){
        select = atoi(input.c_str());
        if (select > 0 && select < maxSize) {
            return select;
        }
        else {
            cout << "Selection does not exist" << endl << endl;
            return -1;
        }
    }
    else {
        cout << "Invalid input" << endl;
        return -1;
    }
}
