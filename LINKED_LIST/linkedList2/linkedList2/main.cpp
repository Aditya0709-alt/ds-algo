#include <iostream>
using namespace std;

class node {
public:
    node* next;
    int data;
    
    node (int val) {
        data = val;
        next = NULL;
    }
};


void insertAtHead (node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
}
void deleteAtHead (node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}

void deleteNode (node* &head, int val) {
    node* temp = head;
    while (temp->next->data != val) {
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
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
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    display(head);
    deleteAtHead(head);
    display(head);

    return 0;
}
