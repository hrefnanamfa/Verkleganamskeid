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

        cout << "Choose your appropriate option" << endl;
        cout << "p: Make pizza" << endl;
        cout << "d: Choose destination" << endl;
        //cout << "l: List ordered pizzas for destination" << endl;
        cout << "s: Select pizza order" << endl;
        cout << "i: Pizza In Progress" << endl;
        cout << "r: Pizza Ready" << endl;
        cout << "q: To go back" << endl;

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
