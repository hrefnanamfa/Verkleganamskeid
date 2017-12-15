#include "../../include/ui/Extrasui.h"

void ExtrasUI::startUI(){
    char selection = '\n';
    while (selection != 'Q'){
        cout << "1. Add an extra item" << endl;
        cout << "2. Edit an extra item" << endl;
        cout << "3. Delete an extra item" << endl;
        cout << "4. View all extra items" << endl << endl;
        cout << "q. to go back" << endl;

        cin >> selection;
        selection = toupper(selection);
        if (selection == '1'){
            createExtras();
        }
        else if (selection == '2'){
            string input;
            int select = 0;
            bool extrasempty;

            do{
                listExtras();
                extrasempty = extras.empty();
                if(!extrasempty){
                    cout << "Select an item to edit" << endl;
                    cin >> input;
                    select = inputSanitize(input, (int)extras.size() + 1);
                }
            }while(select < 0);
            if (!extrasempty) {
                Extras extra;
                cin >> extra;
                extrasservice.replaceAndSaveExtraAt(select - 1, extra);
            }
        }
        else if (selection == '3'){
            string input;
            int select = 0;
            bool extrasempty;
            do{
                listExtras();
                extrasempty = extras.empty();
                if(!extrasempty){
                    cout << "Select an item to delete" << endl;
                    cin >> input;

                    select = inputSanitize(input, (int)extras.size() + 1);
                }
            }while(select < 0);
            if(!extrasempty){
                extrasservice.deleteExtraAndSaveAt(select - 1);
            }
        }
        else if (selection == '4'){
            listExtras();
        }
    cout << endl;
    }
}

bool ExtrasUI::isExtrasVectorEmpty(){
    if(extras.empty()){
        return true;
    }
    else{
        return false;
    }
}

void ExtrasUI::createExtras(){
    Extras extras;
    cin >> extras;
    extrasservice.addExtras(extras);
}

void ExtrasUI::listExtras(){
    extras = extrasservice.listAvailableExtras();

    if(!extras.empty()){
        cout << "- Extras -" << endl;
        for(unsigned int i = 0; i < extras.size(); i++){
            cout << i + 1  << ". " << extras[i].getName();
            if (extras[i].getName().length() > 10)
                cout << "\t\t";
            else
                cout << "  \t\t";
            cout << extras[i].getPrice() << " kr." << endl;
        }
    }
    else if(extras.empty()){
        cout << "There are no extra items registered!" << endl;
    }
}

int ExtrasUI::inputSanitize(string input, int maxSize) {
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

int ExtrasUI::getExtrasVectorSize() {
    return this->extras.size();
}
