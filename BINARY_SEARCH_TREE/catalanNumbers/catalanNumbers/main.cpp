#include <iostream>
#include <vector>
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

int catalan (int n){
    if (n <= 1) {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += catalan(i)*catalan(n-i-1);
    }
    return res;
}

vector<node*> constructTrees (int start, int end){
    vector<node*> trees;
    if (start > end) {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++) {
        vector<node*> leftsubTrees = constructTrees(start, i-1);
        vector<node*> rightsubTrees = constructTrees(i+1, end);
        
        for (int j = 0; j < leftsubTrees.size(); j++) {
            node* left = leftsubTrees[j];
            for (int k = 0; k < rightsubTrees.size(); k++) {
                node* right = rightsubTrees[k];
                node* n = new node(i);
                n->left = left;
                n->right = right;
                trees.push_back(n);
            }
        }
    }
    return trees;
}

void preorder(node *root){
    if (root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main () {
    vector<node*> totalTrees = constructTrees(1, 3);
    for (int i = 0; i < totalTrees.size(); i++) {
        cout<<i+1<<" : ";
        preorder(totalTrees[i]);
        cout<<endl;
    }
    
    return 0;
}
