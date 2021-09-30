#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    
    node(int val){
        next = NULL;
        data = val;
    }
};

void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
}
// Iterative method
node* reverse (node* &head) {
    node* prevptr = NULL;
    node* current = head;
    node* nextptr;
    
    while (current != NULL) {
        nextptr = current->next;
        current->next = prevptr;
        
        prevptr = current;
        current = nextptr;
    }
    return prevptr;
}

// Recursive method

node* reverseRecursive (node* &head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next= NULL;
    
    return newhead;
}

void display(node* head) {
    node *temp = head;
    while (temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main () {
    node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    display(head);
    node* newhead = reverseRecursive(head);
    display(newhead);
    return 0;
}
