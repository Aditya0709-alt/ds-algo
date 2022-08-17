#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     long long int z;
     cin >> z;
     
     while(z--){
         int a, b, c;
         cin >> a >> b >> c;
         if (b >= a && c <= b) cout <<"YES"<<endl;
         else cout << "NO"<<endl;
     }
	return 0;
}
