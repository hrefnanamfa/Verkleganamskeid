#include "Order.h"

Order::Order()
{
    this->paid = false;
    currentStatus = INPROGRESS;
}

Order::~Order()
{
    //dtor
}
