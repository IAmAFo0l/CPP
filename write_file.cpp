// Succesfully compiles and executed using C++17

#include "iostream"
#include "fstream"
using namespace std;

int main(void)
{
    ofstream f;
    string line, fname;
    cout << "Input file name: ";
    cin >> fname;
    cout << "Enter 0 in a new line after finishing writing to the file\n";
    f.open(fname);
    while(getline(cin, line)){
        if(line != "0") f << line << endl;
        else break;
    }
    f.close();
    return 0;
}
