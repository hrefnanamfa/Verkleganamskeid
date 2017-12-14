#include "../../include/ui/Extrasui.h"

ExtrasUI::ExtrasUI()
{
    //ctor
}

ExtrasUI::~ExtrasUI()
{
    //dtor
}

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
            int select = 0;
            listExtras();
            if(!extras.empty()){
                cout << "Select an item to edit" << endl;
                cin >> select;
                Extras extra;
                cin >> extra;
                extrasservice.replaceAndSaveExtraAt(select - 1, extra);
            }
        }
        else if (selection == '3'){
            int select = 0;
            listExtras();
            if(!extras.empty()){
                cout << "Select an item to delete" << endl;
                cin >> select;
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
        cout << "There are no extra items regestired!" << endl;
    }
}
