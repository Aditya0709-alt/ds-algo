#include <iostream>
using namespace std;

int main () {
    
    int n, res = 0;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout<<endl;
    int i = 0;
    while (arr[i] != 0) {
        for ( i = 0; i < n; i++) {
            if (arr[i]%2 == 0) {
                arr[i] /= 2;
                ++res;
            }
                arr[i]--;
                ++res;
        }
    }
    
    cout<<res<<endl;
    
    return 0;
}
