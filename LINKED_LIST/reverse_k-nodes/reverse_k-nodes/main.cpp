#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    
    node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead (node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
}
node* reversek (node* &head, int k) {
    node* prevptr = NULL;
    node* current = head;
    node* nextptr;
    int count = 0;
    while (current != NULL && count<k) {
        nextptr = current->next;
        current->next = prevptr;
        prevptr = current;
        current = nextptr;
        count++;
    }
    if (current != NULL) {
        head->next = reversek(current, k);
    }
    return prevptr;
}

void display (node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


int main () {
    node* head = NULL;
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    display(head);
    int k = 2;
    node* newhead = reversek(head, k);
    display(newhead);
    return 0;
}
