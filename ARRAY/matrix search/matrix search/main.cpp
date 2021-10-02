#include <iostream>
using namespace std;
int main (){
    int n,m,target;
    cout<<"Enter the number of rows and columns\n";
    cin>>n;
    cin>>m;
    int a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Enter the element you want to search\n";
    cin>>target;
    int r = n - 1, c = 0;
    bool found = false;
    while (r >= 0 && c < m) {
        if (a[r][c] == target) {
            found = true;
        }
        if (a[r][c] > target) {
            r--;
        } else {
            c++;
        }
    }
        if (found) {
            cout<<"The element is found\n"<<endl;
        }else{
            cout<<"The element does not exist\n"<<endl;
        }
    return 0;
}
