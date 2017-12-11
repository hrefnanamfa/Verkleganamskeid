#ifndef ORDER_H
#define ORDER_H
#include "Pizza.h"
#include "Extras.h"
#include "Workplaces.h"

enum status { ONHOLD = 1, INPROGRESS, READY, DELIVERED};


class Order
{
    private:
        vector<Pizza> pizzas;
        vector<Extras> extras;
        bool paid;
        status currentStatus;
        int price;
        Workplaces workplaces;

    public:
        Order();
        ~Order();
        void setPrice();
        int getPrice();
        void addPizza(Pizza& pizza);
        void addExtras(Extras& extra);
        void setPizzas(vector<Pizza> pizzas);
        void setExtras(vector<Extras> extras);
        void setCurrentStatus(status _status);
        void setPaid(bool paid);
        void setPickup(Workplaces workplaces);
        string getLocation();
        void checkPaid();
        void checkCurrentStatus();
        friend ostream& operator <<(ostream& out, Order& order);
        friend istream& operator >>(istream& in, Order& order);
        void write(ofstream& fout) const;
        void read(ifstream& fin);

};

#endif // ORDER_H
