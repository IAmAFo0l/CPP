// Succesfully compiles and executed in C++17

#include "iostream"
#include "fstream"
using namespace std;

int main(void)
{
    ifstream f;
    string line, fname;
    cout << "Input file name: ";
    cin >> fname;
    f.open(fname);
    while(getline(f, line))
        cout << line << endl;
    f.close();
    return 0;
}
