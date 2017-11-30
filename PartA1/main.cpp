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
            }//Hér er skrifað upp næstu 10 línur svo lengi sem ekki er komið að enda skjalsins
            do{
                cout << "Do you wish to continue?" << endl;
                cin >> answer;
                counter = 0;

                if (answer == 'n'){
                flagg = false;
                break;
                }

            }while (answer != 'y');//Þessi do while lykkja spyr alltaf aftur sömu spurningu ef svarið er ekki 'y'

        }while(flagg == true);//hérna hættir forritið ef svarið sé 'n'

        fin.close();
        }

    return 0;
}
