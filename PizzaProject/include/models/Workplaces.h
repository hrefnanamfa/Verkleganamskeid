#ifndef WORKPLACES_H
#define WORKPLACES_H
#include <iostream>
#include <fstream>

using namespace std;

class Workplaces
{
    private:
        string name;
        bool verbose;

    public:
        Workplaces();
        string getName() const;
        void setName(string name);
        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend istream& operator >> (istream& in, Workplaces& workplaces);
        friend ostream& operator << (ostream& out, const Workplaces& workplaces);

        ~Workplaces();

};

#endif // WORKPLACES_H
