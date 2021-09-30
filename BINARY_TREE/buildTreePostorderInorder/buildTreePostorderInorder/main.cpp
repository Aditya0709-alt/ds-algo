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


int search(int inorder[], int start, int end, int curr) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == curr) {
            return i;
        }
    }
    return -1;
}

node* buildTree (int postorder[], int inorder[], int start, int end){
    static int idx = 4;
    if (start > end) {
        return NULL;
    }
    int curr = postorder[idx];
    idx--;
    node*  n = new node(curr);
    if (start == end) {
        return n;
    }
    
    int pos = search(inorder,start, end, curr);
    n->right = buildTree(postorder, inorder, pos+1, end);
    n->left = buildTree(postorder, inorder, start, pos-1);
    return n;
    
}

void printInorder (node* root) {
    if (root == NULL) {
        return;
    }
    
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
int main () {
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};
    
    node* root = buildTree(postorder, inorder, 0,4);
    printInorder(root);
    cout<<endl;
    return 0;
}
