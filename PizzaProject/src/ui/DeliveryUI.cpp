#include "DeliveryUI.h"
#include <iostream>

using namespace std;

DeliveryUI::DeliveryUI()
{
    //ctor
}

DeliveryUI::~DeliveryUI()
{
    //dtor
}
void DeliveryUI::startUI(){
    char selection = '\0';

    while(selection != 'Q'){

        cout << "Choose your appropriate option" << endl;
        cout << "d: Choose delivery destination" << endl;
        cout << "l: List orders for destination" << endl;
        cout << "r: List ready orders for destination" << endl;
        cout << "o: Select order" << endl;
        cout << "1: Mark order as paid" << endl;
        cout << "2: Mark order as delivered" << endl;
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
