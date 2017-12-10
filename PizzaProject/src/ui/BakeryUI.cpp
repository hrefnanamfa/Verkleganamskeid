#include "BakeryUI.h"
#include <iostream>

using namespace std;

BakeryUI::BakeryUI()
{
    //ctor
}

BakeryUI::~BakeryUI()
{
    //dtor
}
void BakeryUI::startUI(){
    char selection = '\0';

    while(selection != 'Q'){

        cout << "Please pick an order to flag" << endl;

        orderservice.listOrders();//List orders in process

        cin >> selection;
        selection = toupper(selection);

        if(selection == 'P') {

        }
        else if(selection == 'S') {

        }
        else if(selection == 'B') {

        }
        else if(selection == 'D') {

        }
    }
}
