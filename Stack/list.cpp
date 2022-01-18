#include<iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
    
    Node(int x = 0) {
        data = x;
        next = 0;
    }
};

class Stack {
    Node * top;
    int size;
    
    public :
    
    Stack() {
        top = 0;
        size = 0;
    }
    
    void push(int x) {
        Node * n = new Node(x);
        if(!n) {
            cout<<"Heap Overflow"<<endl;
            return;
        }
        n->next = top;
        top = n;
        size++;
    }
    
    int pop() {
        if(top == 0) {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        int x = top->data;
        Node * temp = top;
        top = top->next;
        delete(temp);
        size--;
        return x;
    }
    
    int peek() {
        if(top == 0) {
            return -1;
        }
        return top->data;
    }
    
    int returnSize() {
        return size;
    }
    
    bool empty() {
        return (top == 0);
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.returnSize()<<endl;
    st.push(4);
    st.push(5);
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.peek()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
}