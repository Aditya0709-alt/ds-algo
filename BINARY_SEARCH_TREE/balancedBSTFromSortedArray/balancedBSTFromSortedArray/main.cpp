#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
    
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* ArrayBST(int arr[], int s, int e) {
    if (s > e) {
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(arr[mid]);
    root->left = ArrayBST(arr, s, mid-1);
    root->right = ArrayBST(arr, mid+1, e);
    
    return root;
}

void displayPreorder (node* root){
    if (root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    displayPreorder(root->left);
    displayPreorder(root->right);
}

int main () {
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* root = ArrayBST(arr, 0, n-1);
    displayPreorder(root);
    cout<<endl;
    return 0;
}
