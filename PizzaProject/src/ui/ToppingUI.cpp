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
            cout << "Select a topping to edit" << endl;
            cin >> select;

        }
        else if (selection == '3'){
            int select = 0;
            listToppings();
            cout << "Select a topping to delete" << endl;
            cin >> select;
        }
        else if (selection == '4'){
            listToppings();
        }
    }
}
void ToppingUI::createTopping(){
    Topping topping;

    cin >> topping;

    toppingservice.addTopping(topping);
}
void ToppingUI::listToppings(){
    cout << "- Toppings -" << endl;
    vector<Topping> toppings = toppingservice.listAvailableToppings();
    for(unsigned int i = 0; i < toppings.size(); i++){
        cout << i + 1 << ". " << toppings[i] << endl;
    }
    cout << endl;
}
