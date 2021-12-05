#include <iostream>
#include <queue>
using namespace std;

typedef struct node {
    int data;
    node* left;
    node*right;
public:
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
}node;

void printLevelOrder (node* root) {
    if (root == NULL) {
        return;
    }
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        node* n  = q.front();
        q.pop();
        if (n != NULL) {
            cout<<n->data<<" ";
            if (n->left) {
                q.push(n->left);
            }
            if (n->right) {
                q.push(n->right);
            }
        }
        else if (!q.empty()) {
            q.push(NULL);
        }
    }
}

int sumAtK (node* root, int k) {
    if (root == NULL) {
        return -1;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;
    
    while (!q.empty()) {
        node* n = q.front();
        q.pop();
        if (n!=NULL) {
            if (level == k) {
                sum += n->data;
            }
            if (n->left) {
                q.push(n->left);
            }
            if (n->right) {
                q.push(n->right);
            }
        }
        else if (!q.empty()) {
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main () {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    printLevelOrder(root);
    cout<<endl;
    cout<<sumAtK(root, 2)<<endl;;
    return 0;
}
