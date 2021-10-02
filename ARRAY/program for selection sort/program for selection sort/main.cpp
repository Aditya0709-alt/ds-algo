#include <iostream>
using namespace std;
int main (){
    int n,a[100],i,j,x;
    cout<<"Enter the size of array\n";
    cin>>n;
    for (i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }
    cout<<"The array in ascending order is\n"<<endl;
    for (i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
