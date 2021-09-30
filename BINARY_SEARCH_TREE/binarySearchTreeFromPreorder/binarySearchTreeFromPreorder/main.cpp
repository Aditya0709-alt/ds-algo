#include <iostream>
using namespace std;

typedef struct node {
    int data;
    node* left;
    node* right;
    
public:
    node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
}node;

node* constructBST (int preorder[], int* preorderIdx, int key, int min, int max, int n) {
    if (*preorderIdx > n) {
        return NULL;
    }
    node* root = NULL;
    if (key > min && key < max) {
        root = new node(key);
        *preorderIdx = *preorderIdx+1;
        
        if (*preorderIdx < n) {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        
        if (*preorderIdx < n) {
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }
    
    return root;
}

void displayPreorder (node* root) {
    if (root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    displayPreorder(root->left);
    displayPreorder(root->right);
}

int main () {
    int preorder[] = {10, 2, 1, 13, 11};
    int n = sizeof(preorder)/sizeof(preorder[0]);
    int preorderIdx = 0;
    node* root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    displayPreorder(root);
    cout<<endl;
    return 0;
}
