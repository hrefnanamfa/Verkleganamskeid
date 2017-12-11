#include "../../include/ui/BaseUI.h"

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

void BaseUI::listBases() {
    cout << "- Bases -" << endl;
    baseservice.listAvailableBases();
}
