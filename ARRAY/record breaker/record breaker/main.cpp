#include <iostream>
using namespace std;
int main (){
    int n,i;
    cout<<"Enter the number of elements in array\n";
    cin>>n;
    int a[n+1];
    a[n] = -1;
    for (i = 0; i < n; ++i) {
        cin>>a[i];
    }
    if (n == 1) {
        cout<<"1"<<endl;
        return 0;
    }
    int ans = 0;
    int mx = -1;
    for (i = 0; i < n; ++i) {
        if (a[i] > mx && a[i] > a[i+1]) {
            ans++;
        }
        mx = max(mx, a[i]);
    }
    cout<<"The number of record breaking days are\n";
    cout<<ans<<endl;
    return 0;
}
