#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    ofstream fout;
    fout.open("text.txt", ios::app);

    bool run = true;
    string s;

    while(run) {
        cin >> s;
        if (s[0] == '\\')
            break;
        fout << s << endl;
    }
    return 0;
}
