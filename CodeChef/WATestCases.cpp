#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     long long int z;
     cin >> z;
     
     while(z--){
         int a,b;
         
         cin >> a;
         vector<int> v;
         
         for(int i=0; i < a; i++){
             cin >> b;
             v.push_back(b);
         }
         
         string s;
         cin >> s;
         
         int minimum = 1000;
         for(int i = 0; i < a; i++){
             if(s[i] == '0' && v[i] < minimum){
                 minimum = v[i];
             }
         }
         cout << minimum << endl;
     }
	return 0;
}
