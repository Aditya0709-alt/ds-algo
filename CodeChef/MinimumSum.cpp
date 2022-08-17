
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     long long int z;
     cin >> z;
     
     while(z--){
         long long int a, b;
         
         cin >> a;
         
         vector<long long int> v;
         
         for(long long int i = 0; i<a;i++){
             cin>>b;
             v.push_back(b);
         }
         
         long long int min_gcd = 1000000000;
         
         for(long long int i = 0; i<a-1;i++){
                 long long int c = gcd(v[i],v[i+1]);
                 if(c < min_gcd) min_gcd = c;
         }
         cout<<min_gcd*a<<endl;
     }
	return 0;
}
