#include "iostream"
using namespace std;

void sort(int arr[], int size)
{
    for(int i = 1; i < size; ++i)
        for(int j = i-1; arr[j] > arr[i] && j >= 0; --j, --i){
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
}

int main()
{
    int a, b;
    cout << "Size of first array: ";
    cin >> a;
    int arr[a];
    cout << "Enter elements of first array separated by space(s): ";
    for(int i = 0; i < a; ++i) cin >> arr[i];
    sort(arr, a);
    cout << "Size of second array: ";
    cin >> b;
    int brr[b];
    cout << "Enter elements of second array separated by space(s): ";
    for(int i = 0; i < b; ++i) cin >> brr[i];
    sort(brr, b);
    int i = 0, j = 0, t = -1, k = -1, uni[a+b], inter[(a<b)?a:b];
    while(i < a && j < b){
        while(brr[j] < arr[i] && j < b) uni[++t] = brr[j++];
        if(brr[j] == arr[i]){
            uni[++t] = brr[j++];
            inter[++k] = arr[i++];
        }
        else uni[++t] = arr[i++];
    }
    while(i > a-1 && j < b) uni[++t] = brr[j++];
    while(i < a && j > b-1) uni[++t] = arr[i++];
    cout << "Intersection of the two given arrays: ";
    for(int i = 0; i <= k; cout << inter[i++] << ' '){}
    cout << endl;
    cout << "Union of the two given arrays: ";
    for(int i = 0; i <= t; cout << uni[i++] << ' '){}
    cout << endl;
}
