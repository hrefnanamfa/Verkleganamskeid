#ifndef EXTRAS_H
#define EXTRAS_H
#include <iostream>
#include <fstream>

using namespace std;

class Extras
{
    private:
    string name;
    int price;
    bool verbose;

    public:
        Extras();
        int getPriceOfExtras();
        void setVerbose(bool setting);
        void setName(string name);
        void setPrice(int price);
        string getName() const;
        int getPrice() const;
        void write(ofstream& fout) const;
        void read(ifstream& fin);
        friend istream& operator >> (istream& in, Extras& extras);
        friend ostream& operator << (ostream& out, const Extras& extras);

};

#endif // EXTRAS_H
