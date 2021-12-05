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

int countNodes (node* root) {
    if (root == NULL) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes (node* root) {
    
    if (root == NULL) {
        return 0;
    }
    return sumNodes(root->left)+sumNodes(root->right)+root->data;
}

int main () {
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    cout<<countNodes(root)<<endl;
    cout<<sumNodes(root)<<endl;
    return 0;
}
