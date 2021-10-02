#include <iostream>
using namespace std;
int main (){
    int n,a[100],i,x = 1,temp;
    cout<<"Enter the value of n\n";
    cin>>n;
    for (i = 0; i < n; ++i) {
        cin>>a[i];
    }
    while (x < n) {
        for (i = 0; i < n - x ; ++i) {
            if (a[i] > a[i+1]) {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        ++x;
    }
    for (i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}
