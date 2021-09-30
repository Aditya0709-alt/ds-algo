#include <iostream>
using namespace std;

typedef struct node {
    int data;
    node *left, *right;
    
public:
    node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
}node;

node* insertBST (node* root, int val) {
    if (root == NULL) {
        return new node(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    }
    if (val > root->data) {
        root->right = insertBST(root->right, val);
    }
    return root;
}
bool search (node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (key == root->data) {
        return true;
    } else if (key < root->data) {
        return search(root->left, key);
    } else if (key > root->data) {
        return search(root->right, key);
    }
    return false;
}

node* inorderSucc(node* root) {
    node* curr = root;
    while (curr != NULL && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

node* deleteBST (node* root, int key) {
    if (key < root->data) {
        root->left = deleteBST(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteBST(root->right, key);
    }
    else {
        if (root->left == NULL) {
            node* temp  = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        } else {
            node* temp = inorderSucc(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
    }
    return root;
}

void inorder (node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main () {
    int arr[] = {6,2,1,4,5,3,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* root = NULL;
    root = insertBST(root, 6);
    for (int i = 1; i < n; i++) {
        insertBST(root, arr[i]);
    }
    
    inorder(root);
    cout<<endl;
    cout<<search(root, 9)<<endl;
    node* root1 = deleteBST(root, 2);
    inorder(root1);
    cout<<endl;
    return 0;
}
