#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SuperHero
{
    private:
        string name;
        int age;
        char super;
        bool verbose;

    public:
        SuperHero();
        SuperHero(string name, int age, char super);
        void setVerbose(bool flag);
        friend ostream& operator<<(ostream& out, const SuperHero& hero);
        friend istream& operator>>(istream& in, SuperHero& hero);
};

SuperHero::SuperHero() {
    name = "";
    age = 0;
    super = 'n';
    verbose = true;
}

SuperHero::SuperHero(string name, int age, char super) {
    this->name = name;
    this->age = age;
    this->super = super;
}

istream& operator>>(istream& in, SuperHero& hero) {
    cout << "Enter name: ";

    in >> hero.name;

    cout << "Enter age: ";

    in >> hero.age;

    cout << "Enter superpower: ";

    in >> hero.super;

    return in;
}

ostream& operator<<(ostream& out, const SuperHero& hero) {

    out << hero.name;
    out << "(";
    out << hero.age;

    out << "): ";

    if(hero.super == 'f'){
        out << "Flying";
    }
    else if(hero.super == 'g'){
        out << "Giant";
    }
    else if(hero.super == 'h'){
        out << "Hacker";
    }
    else if(hero.super == 'n'){
        out << "None";
    }
    else{
        out << "Weakling";
    }

    out << endl;

    return out;
}

int main()
{
    ofstream fout;
    ifstream fin;
    SuperHero hero;

    cin >> hero;
    cout << "How many heros?" << endl;
    cin >> size;

    SuperHero* Superheros = new SuperHero[size];

    for(int i = 0; i < size; i++){
        cin >> hero;
    }

    fout.open("binary_file.dat", ios::binary|ios::app);
    fout.write((char*)(&hero), sizeof(SuperHero));
    fout.close();


    return 0;
}
