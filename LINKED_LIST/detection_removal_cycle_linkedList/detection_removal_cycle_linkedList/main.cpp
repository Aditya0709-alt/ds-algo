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

void insertAthead (node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
}

void makeCycle (node* &head, int pos) {
    node* temp = head;
    node* startNode;
    int count = 1;
    while (temp->next != NULL) {
        if (count == pos) {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectCycle (node* &head) {
    node* slow = head;
    node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (fast == slow) {
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;
    
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != slow);
    
    fast = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
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
    for (int i = 7; i > 0; i--) {
        insertAthead(head, i);
    }
    display(head);
    makeCycle(head, 3);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    return 0;
}
