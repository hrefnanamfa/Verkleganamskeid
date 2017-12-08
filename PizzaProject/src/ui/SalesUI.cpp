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

        cout << "Let's make an order!" << endl;
        cout << "1: Add a pizza from menu" << endl;
        cout << "2: Add your own pizza" << endl;
        cout << "3: Add something extra" << endl;
        cout << "4: Delivery/pickup options" << endl;
        cout << "5: Order payment status" << endl;
        cout << "6: Add comment to order" << endl;
        cout << "7: To go back" << endl;

        cin >> selection;
        selection = toupper(selection);

        if(selection == '1') {

        }
        else if(selection == '2') {

        }
        else if(selection == '3') {

        }
        else if(selection == '4') {

        }
    }
}
