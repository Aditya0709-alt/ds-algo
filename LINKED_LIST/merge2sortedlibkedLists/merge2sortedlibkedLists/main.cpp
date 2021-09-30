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

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* merge(node* &head1,node* &head2) {
    node* p1 = head1;
    node* p2 = head2;
    node* dummy = new node(-1);
    node* p3 = dummy;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            p3->next = p1;
            p1 = p1->next;
        }
        else {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1 != NULL) {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL) {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy->next;
}

node* mergeRecursive(node* &head1, node* &head2) {
    node* result;
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    if (head1->data < head2->data) {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    } else {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}

int main () {
    node* head1 = NULL;
    node* head2 = NULL;
    cout<<"Linked list 1"<<endl;
    for (int i = 4; i > 0; i--) {
        insertAtHead(head1, i);
    }
    display(head1);
    cout<<"\nLinked list 2"<<endl;
    for (int i = 8; i > 5; i--) {
        insertAtHead(head2, i);
    }
    display(head2);
    cout<<"\nMerged Sorted Linked list"<<endl;
    node* newhead = mergeRecursive(head1, head2);
    display(newhead);
    cout<<endl;
    return 0;
}
