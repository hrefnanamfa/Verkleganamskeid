#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>
#include <fstream>

using namespace std;

class Topping
{
    private:
        string name;
        int price;
        bool verbose;


    public:
        Topping();
        void setVerbose(bool setting);
        void setName(string name);
        void setPrice(int price);
        string getName() const;
        int getPrice() const;
        void write(ofstream& fout) const;
        void read(ifstream& fin);
        friend istream& operator >> (istream& in, Topping& topping);
        friend ostream& operator << (ostream& out, const Topping& topping);

};

#endif // TOPPING_H
