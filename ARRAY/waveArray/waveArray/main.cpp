#include <iostream>
using namespace std;

void waveSort (int arr[], int n) {
    int i = 0;
    if (n == 0) {
        cout<<"Sorry, array is empty"<<endl;
    }
    if (n%2 == 0) {
        while (i < n) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            i += 2;
        }
    } else {
        int last = arr[n-1];
        while (i < n-2) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            i += 2;
            arr[n-1] = last;
        }
    }
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main () {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    waveSort(arr, n);
    cout<<endl;
    return 0;
}
