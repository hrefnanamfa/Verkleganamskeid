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
    cin >> base;

    baseservice.addBase(base);
}

void BaseUI::listBases() {
    cout << "- Bases -" << endl;
    baseservice.listAvailableBases();
}
