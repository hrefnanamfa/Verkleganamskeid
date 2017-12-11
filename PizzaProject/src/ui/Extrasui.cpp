#include "../../include/ui/ExtrasUI.h"

ExtrasUI::ExtrasUI()
{
    //ctor
}

ExtrasUI::~ExtrasUI()
{
    //dtor
}

void ExtrasUI::createExtras(){
    Extras extras;
    cin >> extras;

    extrasservice.addExtras(extras);
}

void ExtrasUI::listExtras(){
    cout << "- Extras -" << endl;
    extrasservice.listAvailableExtras();
}
