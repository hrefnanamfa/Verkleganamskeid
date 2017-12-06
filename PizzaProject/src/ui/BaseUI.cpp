#include "BaseUI.h"

BaseUI::BaseUI()
{
    //ctor
}

BaseUI::~BaseUI()
{
    //dtor
}
void BaseUI::createBase(){
    Base base;
    cout << "Creating base" << endl;
    cin >> base;

    baseservice.addBase(base);
}
