#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <fstream>

using namespace std;

class Base
{
    private:
        string name;
        double price;
        bool verbose;

    public:
        Base();
        string getName() const;
        double getPrice() const;
        void setName(string name);
        void setPrice(double price);
        void setVerbose(bool setting);
        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend istream& operator >> (istream& in, Base& base);
        friend ostream& operator << (ostream& out, const Base& base);

        ~Base();

};

#endif // BASE_H
