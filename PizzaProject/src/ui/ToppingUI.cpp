#include "../../include/ui/ToppingUI.h"

ToppingUI::ToppingUI()
{
    //ctor
}

ToppingUI::~ToppingUI()
{
    //dtor
}
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
            int select = 0;
            listToppings();
            if(!toppings.empty()){
                cout << "Select a topping to edit" << endl;
                cin >> select;
                Topping topping;
                cin >> topping;
                toppingservice.replaceAndSaveToppingAt(select - 1, topping);
            }
        }
        else if (selection == '3'){
            int select = 0;
            listToppings();
            if(!toppings.empty()){
                cout << "Select a topping to delete" << endl;
                cin >> select;
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
