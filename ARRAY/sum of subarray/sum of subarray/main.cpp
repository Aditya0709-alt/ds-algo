#include <iostream>
using namespace std;
int main (){
    int n, a[100],i,j,current = 0;
    cout<<"Enter the size of array\n";
    cin>>n;
    for (i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (i = 0; i < n; ++i) {
        current  = 0;
        for (j = i; j < n ; ++j) {
            current += a[j];
            cout<<"The sum is "<<current<<endl;
        }
    }
    return 0;
}
