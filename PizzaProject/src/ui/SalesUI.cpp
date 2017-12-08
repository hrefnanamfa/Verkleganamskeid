#include "SalesUI.h"
#include <iostream>
using namespace std;
SalesUI::SalesUI()
{
    //ctor
}

SalesUI::~SalesUI()
{
    //dtor
}
void SalesUI::startUI(){
     char selection = '\0';

    while(selection != 'Q'){

        cout << "Choose your appropriate option" << endl;
        cout << "o: Create a new order" << endl;
        cout << "a: Add pizza to order" << endl;
        cout << "p: Print order price" << endl;
        cout << "d: Delivery/pickup options" << endl;
        cout << "s: Order payment status" << endl;
        cout << "c: Add comment to order" << endl;
        cout << "q: To go back" << endl;

        cin >> selection;
        selection = toupper(selection);

        if(selection == 'M') {

        }
        else if(selection == 'S') {

        }
        else if(selection == 'B') {

        }
        else if(selection == 'D') {

        }
    }
}
