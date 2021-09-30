#include <iostream>
using namespace std;


//Sorting algorithms for array
void selectionSort(int a[], int n) {
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
}


void bubbleSort(int a[], int n) {
    int count = 1;
    while (count < n-1) {
        for (int i = 0; i < n - count; i++) {
            if (a[i] > a[i+1]) {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        count++;
    }
    
    for (int i =0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main () {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    
    //selectionSort(a, n);
    bubbleSort(a, n);
    return 0;
}
