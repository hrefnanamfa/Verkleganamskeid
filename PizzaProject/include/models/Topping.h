#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>
#include <fstream>
using namespace std;

class Topping
{
    private:
        string name;
        double price;
        bool verbose;

    public:
        Topping();
        void setVerbose(bool setting);
        void setName(string name);
        void setPrice(double price);
        string getName() const;
        double getPrice() const;
        void write(ofstream& fout) const;
        void read(ifstream& fin);
        friend istream& operator >> (istream& in, Topping& topping);
        friend ostream& operator << (ostream& out, const Topping& topping);
        ~Topping();

};

#endif // TOPPING_H
