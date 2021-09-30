#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack <int> &st, int el) {
    if (st.empty()) {
        st.push(el);
        return;
    }
    int topel = st.top();
    st.pop();
    insertAtBottom(st, el);
    st.push(topel);
}

void reverse (stack<int> &st) {
    if (st.empty()) {
        return;
    }
    int el = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, el);
    
}

int main () {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
     reverse(st);
    while (!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}
