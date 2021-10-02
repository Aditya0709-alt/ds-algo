#include <iostream>
using namespace std;
int main (){
    int n,a[100],i,current,j;
    cout<<"Enter the size of the array\n"<<endl;
    cin>>n;
    cout<<"\n";
    for (i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (i = 1; i < n; ++i) {
        current = a[i];
        j = i - 1;
    while (a[j] > current && j>= 0) {
        a[j+1] = a[j];
        j--;
    }
        a[j+1] = current;
    }
    for (i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
