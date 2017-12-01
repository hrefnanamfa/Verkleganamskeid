#include "Size.h"

Size::Size(int inches)
{
    this->inches = inches;
}

Size::~Size()
{
    //dtor
}
void Size::setSize(int inches){
    this->inches = inches;
}
