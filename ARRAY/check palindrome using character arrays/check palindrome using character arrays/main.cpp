#include <iostream>
using namespace std;
int main (){
    int n;
    cin>>n;
    char a[n+1];
    cin>>a;
    bool check = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[n -1-i]) {
            check = 0;
            break;
        }
    }
    if (check == true) {
        cout<<"The word is a palindrome\n";
    }else{
        cout<<"The word is not a palindrome\n";
    }
    return 0;
}
