#include "iostream"
#include "algorithm"
using namespace std;

int main()
{
    int a, b;

    // Constructing array
    cout << "Size of first array: ";
    cin >> a;
    int arr[a];
    cout << "Enter elements of first array: ";
    for(int i = 0; i < a; ++i) cin >> arr[i];
    cout << "Size of second array: ";
    cin >> b;
    int brr[b];
    cout << "Enter elements of second array: ";
    for(int i = 0; i < b; ++i) cin >> brr[i];

    // Sorting using built-in function from "algorithm" header
    sort(arr, arr+a);
    sort(brr, brr+b);

    // Simultaneous Union and Intersection construction for minimum iteration
    int i = 0, j = 0, t = -1, k = -1, uni[a+b], inter[(a<b)?a:b];
    while(i < a && j < b){
        while(brr[j] < arr[i] && j < b) uni[++t] = brr[j++];
        if(brr[j] == arr[i]){
            uni[++t] = brr[j++];
            inter[++k] = arr[i++];
        }
        else uni[++t] = arr[i++];
    }
    
    // Taking in remaining elements into union
    while(i > a-1 && j < b) uni[++t] = brr[j++];
    while(i < a && j > b-1) uni[++t] = arr[i++];

    // Printing results
    cout << "Intersection of the given arrays: ";
    for(int i = 0; i <= k; cout << inter[i++] << ' ');
    cout << endl;

    cout << "Union of the given arrays: ";
    for(int i = 0; i <= t; cout << uni[i++] << ' ');
    cout << endl;
}
