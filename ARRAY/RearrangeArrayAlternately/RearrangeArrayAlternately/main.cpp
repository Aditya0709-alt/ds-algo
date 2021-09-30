#include <iostream>
using namespace std;

void rearrange (int arr[], int n) {
    int temp[n];
    int small = 0, large = n-1;
    int check = true;
    
    for (int i = 0; i < n; i++) {
        if (check) {
            temp[i] = arr[large--];
        } else {
            temp[i] = arr[small++];
        }
        check = !check;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main () {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    rearrange(arr, n);
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
