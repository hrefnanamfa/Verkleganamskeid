#include "../../include/ui/ToppingUI.h"

void ToppingUI::startUI(){
    char selection = '\n';
    while (selection != 'Q'){
        cout << "1. Add a topping" << endl;
        cout << "2. Edit a topping" << endl;
        cout << "3. Delete a topping" << endl;
        cout << "4. View all toppings" << endl << endl;
        cout << "q. to go back" << endl;

        cin >> selection;
        selection = toupper(selection);
        if (selection == '1'){
            createTopping();
        }
        else if (selection == '2'){
            string input;
            int select = 0;
            bool toppingsempty;

            do{
                listToppings();
                toppingsempty = toppings.empty();
                if(!toppingsempty){
                    cout << "Select a topping to edit" << endl;
                    cin >> input;
                    select = inputSanitize(input, (int)toppings.size() + 1);
                }
            }while(select < 0);
            if (!toppingsempty){
                Topping topping;
                cin >> topping;
                toppingservice.replaceAndSaveToppingAt(select - 1, topping);

            }
        }
        else if (selection == '3'){
            string input;
            int select;
            bool toppingsempty;
            do{
                listToppings();
                toppingsempty = toppings.empty();
                if(!toppingsempty){
                    cout << "Select a topping to delete" << endl;
                    cin >> input;
                    select = inputSanitize(input, (int)toppings.size() + 1);
                }
            }while(select < 0);
            if (!toppingsempty) {
                 toppingservice.deleteToppingAtAndSave(select - 1);
            }
        }
        else if (selection == '4'){
            listToppings();
        }
        cout << endl;
    }
}

void ToppingUI::createTopping(){
    Topping topping;
    cin >> topping;
    toppingservice.addTopping(topping);
}

bool ToppingUI::isToppingVectorEmpty(){
    toppings = toppingservice.listAvailableToppings();
    if(toppings.empty()){
        return true;
    }
    else{
        return false;
    }
}

void ToppingUI::listToppings(){
    toppings = toppingservice.listAvailableToppings();

    if(!toppings.empty()){
        cout << "- Toppings -" << endl;
        for(unsigned int i = 0; i < toppings.size(); i++){
            cout << i + 1 << ". " << toppings[i] << endl;
        }
    }
    else if(toppings.empty()){
        cout << "There are no toppings registered!" << endl;
    }
}

int ToppingUI::getToppingVectorSize(){
    return toppings.size();
}

int ToppingUI::inputSanitize(string input, int maxSize) {
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
