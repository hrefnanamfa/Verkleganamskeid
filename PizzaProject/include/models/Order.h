#ifndef ORDER_H
#define ORDER_H
#include "Pizza.h"
#include "Extras.h"
#include "Workplaces.h"


class Order
{
    private:
        vector<Pizza> pizzas;
        vector<Extras> extras;
        bool paid;
        int currentStatus;
        int price;
        Workplaces workplaces;
        string comment;

    public:
        Order();
        ~Order();
        void setPrice();
        int getPrice();
        int getStatus();
        void addPizza(Pizza& pizza);
        void addExtras(Extras& extra);
        void setPizzas(vector<Pizza> pizzas);
        void setExtras(vector<Extras> extras);
        void setCurrentStatus(int status);
        void setPaid(bool paid);
        void setPickup(Workplaces workplaces);
        void setComment(string comment);
        string getLocation();
        bool checkPaid();
        void checkCurrentStatus();
        friend ostream& operator <<(ostream& out, Order& order);
        friend istream& operator >>(istream& in, Order& order);
        void write(ofstream& fout) const;
        void read(ifstream& fin);
        string getComment();

};

#endif // ORDER_H
