#include "iostream"
using namespace std;

int main()
{
    int size, val, top = -1;
    string key;
    cout << "Stack size: ";
    cin >> size;
    int stack[size];
    while(true){
        cout << "Type 'push (value)' to push and 'pop' to pop: ";
        cin >> key;
        if(key == "push"){
            cin >> val;
            ++top;
            if(top == size){
                cout << "Stack Overflow\n";
                break;
            }
            stack[top] = val;
            cout << "Stack so far: [ ";
            for(int i = 0; i <= top; ++i) cout << stack[i] << ' ';
            cout << ']' << endl;
        }
        else if(key == "pop"){
            if(top == -1){
                cout << "Underflow\n";
                break;
            }
            --top;
            cout << "Stack so far: [ ";
            for(int i = 0; i <= top; ++i) cout << stack[i] << ' ';
            cout << ']' << endl;
        }
    }
    return 0;
}
