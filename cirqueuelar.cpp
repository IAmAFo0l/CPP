#include "iostream"
using namespace std;

int main()
{
    int size, r = -1, f = -1;
    cout << "Size of queue: ";
    cin >> size;
    int q[size], val;
    string key;
    while(true){
        cout << "Enter 'push (value)' to push and 'pop' to pop: ";
        cin >> key;
        if(key == "push"){
            cin >> val;
            ++r;
            if(r%size == f%size){
                cout << "Queue Overflow!\n";
                break;
            }
            q[r%size] = val;
            if(f == -1) f = 0;
        }
        if(key == "pop"){
            if(f == -1 && r == -1){
                cout << "Queue Underflow\n";
                break;
            }
            ++f;
            if(f%size == (r+1)%size){
                f = -1;
                r = -1;
            }
        }
        for(int i = f; i <= r; ++i){
            if(i != -1) cout << q[i%size] << ' ';
            else cout << ' ';
        }
        cout << endl;
    }
}
