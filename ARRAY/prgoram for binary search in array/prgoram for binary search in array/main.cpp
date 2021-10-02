#include <iostream>
using namespace std;
int binarySearch( int a[], int n , int key){
    int s=0, e = n;
    while (s <= e) {
        int mid = (s+e)/2;
    
    if (a[mid] == key) {
        return mid;
    }
    else if (a[mid] > key){
        e = mid -1;
    }
    else{
        e = mid + 1;
    }
    }
    return -1;
}

int main (){
    int n,i,a[100],key;
    cout<<"Enter the size of array\n";
    cin>>n;
    for (i = 0; i < n; ++i) {
        cin>>a[i];
         }
    cout<<"Enter the key\n";
    cin>>key;
    cout<<"The element is found at index "<<binarySearch(a, n, key)<<endl;
    return 0;
}

