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
        bool pickup;
        string address;
        int addressNumber;

    public:
        Order();
        ~Order();
        void setPrice();
        int getPrice();
        int getStatus();
        string getAddress();
        int getAddressNumber();
        void addPizza(Pizza& pizza);
        void addExtras(Extras& extra);
        void setPizzas(vector<Pizza> pizzas);
        void setExtras(vector<Extras> extras);
        void setCurrentStatus(int status);
        void setPaid(bool paid);
        void setWorkplace(Workplaces workplaces);
        void setComment(string comment);
        void setPickup(bool pickup);
        void setAddress(string address, int addressNumber);
        string getLocation();
        bool checkPaid();
        bool checkIfPickup();
        void checkCurrentStatus();
        int getCurrentStatus();
        friend ostream& operator <<(ostream& out, Order& order);
        friend istream& operator >>(istream& in, Order& order);
        void write(ofstream& fout) const;
        void read(ifstream& fin);
        string getComment();

};

#endif // ORDER_H
