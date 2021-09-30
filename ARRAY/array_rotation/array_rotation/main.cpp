#include <iostream>
using namespace std;
// Array rotation

void rotateByOne(int arr[], int n) {
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++){
            arr[i] = arr[i + 1];
    }
        arr[n-1] = temp;
}

void leftRotate (int arr[], int d, int n) {
    for (int i = 0; i < d;i++) {
        rotateByOne(arr, n);
    }
}

void print(int arr[], int n) {
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
    int d;
    cin>>d;
    leftRotate(arr, d, n);
    print(arr, n);
    return 0;
}
