#include <iostream>
using namespace std;
int main (){
    int n,m;
    cin>> n >> m;
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
    cout<<"\n\n";
    //Finding transpose of the matrix;
    int transpose[m][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            transpose[j][i] = a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j= 0; j < m; ++j) {
            cout<<transpose[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
