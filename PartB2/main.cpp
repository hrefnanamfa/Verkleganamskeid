#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
const int MAX_NAME_LENGTH = 20;

class SuperHero
{
    private:
        char name[MAX_NAME_LENGTH];
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
    name[0] = '\0';
    age = 0;
    super = 'n';
}

ostream& operator<<(ostream& out, const SuperHero& hero) {
    if(hero.verbose) {
        cout << "Name: ";
    }
    out << hero.name;

    if(hero.verbose) {
        cout << endl << "Age: ";
    }
    out << hero.age;

    if(hero.verbose) {
        cout << endl << "Superpower: ";
    }
        if (hero.super == 'f')
            out << "Flying" << " ";
        else if (hero.super == 'g')
            out << "Giant" << " ";
        else if (hero.super == 'h')
            out << "Hacker" << " ";
        else if (hero.super == 'n')
            out << "None" << " ";
        else
            out << "Weakling" << " ";

            cout << endl;

    return out;
}

void SuperHero::setVerbose(bool flag) {
    verbose = flag;
}

istream& operator>>(istream& in, SuperHero& hero) {

    if(hero.verbose)
    {
        cout << endl << "Enter name: ";
    }
    in >> hero.name;

    if(hero.verbose)
    {
        cout << "Enter age: ";
    }
    in >> hero.age;

    if(hero.verbose)
    {
        cout << "Enter power: ";
    }
    in >> hero.super;

    return in;
}

int get_amount_of_heroes()
{
    int amount = 0;
    cout << "How many superheroes would you like to create? ";
    cin >> amount;
    return amount;
}

int main()
{
    ///Declarations
    ofstream fout;
    ifstream fin;

    int hero_amount = get_amount_of_heroes();
    vector <SuperHero> hero_array(hero_amount);

    ///Start of main function.
    //Write in all the super heroes.
    for(int i = 0; i < hero_amount; i++)
    {
        hero_array[i].setVerbose(true);
        cin >> hero_array[i];
    }

    //Print all super heroes into a binary file.
    fout.open("binary_hetjur.dat", ios::binary|ios::app);

    for(int i = 0; i < hero_amount; i++)
    {
        fout.write((char*)(&hero_array[i]), sizeof(SuperHero));
    }

    fout.close();

    fin.open("binary_hetjur.dat", ios::binary);

    if(fin.is_open())
    {
        fin.seekg(0, fin.end);
        int recordCount = fin.tellg() / sizeof(SuperHero);
        fin.seekg(0);

        vector <SuperHero> new_hero_array(recordCount);

        //Get all super heroes in binary file and print them to the screen.
        for(int i = 0; i < recordCount; i++)
        {
            fin.read((char*)(&new_hero_array[i]), sizeof(SuperHero));
            cout << new_hero_array[i] << endl;
        }
    }
    else
    {
        cout << "File isn't open!!";
    }

    return 0;
}
