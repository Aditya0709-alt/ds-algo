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

void insertAtHead (node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
}

int length( node* &head) {
    node* temp = head;
    int counter = 0, a = 1;
    if (head->next == NULL) {
        return a;
    }
    while (temp != NULL) {
        ++counter;
        temp = temp->next;
    }
    return counter;
}

int printMiddle (node* &head) {
    node* temp = head;
    node* fast = head;
    node* slow = head;
    int len = length(head);
    if (len % 2 ==0) {
        while (fast != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
    }
    int score = 0;
    while (temp != NULL && score < (len)/2) {
        temp = temp->next;
        score++;
    }
    return temp->data;
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
    for (int i = 5; i > 0; i--) {
        insertAtHead(head, i);
    }
    display(head);
    cout<<length(head)<<endl;
    cout<<printMiddle(head)<<endl;
    return 0;
}
