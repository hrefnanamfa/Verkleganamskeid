#include <iostream>
#include <fstream>
int SIZE = 10;
using namespace std;


int main()
{
    ifstream fin;
    string str;
    int counter = 0;
    char answer = 'y';
    bool flagg = true;

    fin.open("texti.txt");

    if(fin.is_open()){
        do{
            while(!fin.eof() && counter < SIZE){
                getline(fin, str);
                cout << str << endl;
                counter++;
            }
            if (fin.eof()){
                break;
            }//H�r er skrifa� upp n�stu 10 l�nur svo lengi sem ekki er komi� a� enda skjalsins
            do{
                cout << "Do you wish to continue?" << endl;
                cin >> answer;
                counter = 0;

                if (answer == 'n'){
                flagg = false;
                break;
                }

            }while (answer != 'y');//�essi do while lykkja spyr alltaf aftur s�mu spurningu ef svari� er ekki 'y'

        }while(flagg == true);//h�rna h�ttir forriti� ef svari� s� 'n'

        fin.close();
        }

    return 0;
}
