#include <iostream>
using namespace std;
int main (){
    int mx = -199999,n,a[100],i;
    cout<<"Enter the size of array\n";
    cin>>n;
    for (i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (i = 0;  i < n ; ++i) {
        mx = max(mx, a[i]);
        cout<<"The maximum element is\n"<<mx<<endl;
    }
    return 0;
}
