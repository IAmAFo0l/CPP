#include "iostream"
#include "fstream"
using namespace std;

int main(void)
{
    fstream f;
    string line, fname;
    cout << "Input file name: ";
    cin >> fname;
    cout << "Enter 0 in a new line after finishing writing to the file\n";
    f.open(fname);
    while(getline(cin, line)){
        if(line != "0") f << line;
        else break;
    }
    f.close();
    return 0;
}
