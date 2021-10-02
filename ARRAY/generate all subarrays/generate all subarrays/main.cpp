#include <iostream>
using namespace std;
void subArray(int arr[], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            for (int k = i; k <= j; ++k) {
                cout<<arr[k]<<" "<<endl;
            }
        }
    }
}


int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"All the empty subarrays are\n";
    subArray(arr, n);
    cout<<endl;
    return 0;
}
