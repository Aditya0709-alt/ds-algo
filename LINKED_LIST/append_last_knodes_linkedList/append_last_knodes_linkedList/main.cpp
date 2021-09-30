#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    
    node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
}

int length(node* &head) {
    node* temp = head;
    int l = 0;
    while (temp != NULL) {
        temp = temp->next;
        l++;
    }
    return l;
}

node* kappend(node* &head, int k) {
    node* newHead;
    node* newTail;
    node* tail = head;
    
    int l = length(head);
    k = k%l;
    int count = 1;
    while (tail->next != NULL) {
        if (count == l-k) {
            newTail = tail;
        }
        if (count == l-k+1) {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}


void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main () {
    node* head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    display(head);
    node* newHead = kappend(head, 3);
    display(newHead);
    return 0;
}
