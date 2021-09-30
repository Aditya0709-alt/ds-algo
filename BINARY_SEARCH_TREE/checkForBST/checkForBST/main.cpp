#include <iostream>
using namespace std;


struct node {
    int data;
    node *left, *right;
    
public:
    node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool checkBST (node *root, node* min, node* max) {
    if (root == NULL) {
        return true;
    }
    if (min != NULL && root->data <= min->data) {
        return false;
    }
    if (max != NULL && root->data >= max->data) {
        return false;
    }
    
    bool leftValid = checkBST(root->left, min, root);
    bool rightValid = checkBST(root->right, root, max);
    
    return leftValid && rightValid;
}

int main () {
    node* root = new node(5);
    root->left = new node(2);
    root->right = new node(8);
    if (checkBST(root, NULL, NULL)) {
        cout<<"Valid BST"<<endl;
    } else {
        cout<<"Invalid BST"<<endl;
    }
    return 0;
}
