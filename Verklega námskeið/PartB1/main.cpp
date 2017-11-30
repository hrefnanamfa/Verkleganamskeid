#include <iostream>
#include <fstream>

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
    out << " (";
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

void SuperHero::setVerbose(bool flag) {
    verbose = flag;
}

int main()
{
    ofstream fout;
    ifstream fin;

    SuperHero hero;

    fout.open("hetjur.txt", ios::app);

    cin >> hero;
    hero.setVerbose(false);

    fout << hero << endl;

    fout.close();

    fin.open("hetjur.txt");

    string s;
    hero.setVerbose(false);

    if(fin.is_open()) {
        while(!fin.eof()){
            getline(fin, s);
            cout << s << endl;
        }
    }
    else{
        cout << "Could not open file" << endl;
    }
    fin.close();

    return 0;
}
