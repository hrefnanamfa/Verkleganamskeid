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
            int select = 0;
            listBases();
            if(!bases.empty()){
                cout << "Select a base to edit" << endl;
                cin >> select;
                Base base;
                cin >> base;
                baseservice.replaceAndSaveBaseAt(select - 1, base);
            }
        }
        else if (selection == '3'){
            int select = 0;
            listBases();
            if(!bases.empty()){
                cout << "Select a base to delete" << endl;
                cin >> select;
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
