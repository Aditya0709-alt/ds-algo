#include <iostream>
using namespace std;
int main (){
    int n,i,ans = 2,j = 2;
    cin>>n;
    int a[n];
    for (i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int pd = a[1] - a[0],curr = 2;
    while (j < n) {
        if (pd == a[j] - a[j-1]) {
            curr++;
        }
        else{
            pd = a[j]-a[j-1];
            curr = 2;
        }
        ans = max(ans, curr);
        j++;
    }
    cout<<"\n";
    cout<<"The length of longest subarray is\n";
    cout<<ans<<endl;
    return 0;
}
