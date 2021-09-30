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
    node* n  = new node(val);
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

int count(node* head1, node* head2, int X) {
    node* p1 = head1;
    node* p2 = head2;
    int count=0;
    while (p1 != NULL && p2 != NULL) {
        if ((p1->data+p2->data) == X) {
            count++;
        }
        p2 = p2->next;
        p1 = p1->next;
    }
    return count;
}

int main () {
    node* head1 = NULL;
    node* head2 = NULL;
    int arr1[] = {1,2,3,4,5,6};
    int arr2[] = {11,12,13};
    for (int i = 0; i < 6; i++) {
        insertAtHead(head1, arr1[i]);
    }
    display(head1);
    
    for (int i = 0; i < 3; i++) {
        insertAtHead(head2, arr2[i]);
    }
    display(head2);
    int X = 15;
    cout<<count(head1, head2,X)<<endl;
    return 0;
}
