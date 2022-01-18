#include<iostream>

using namespace std;

class Stack {
    int * s;
    int top;
    int size;
    public :
    Stack(int n = 0) {
        top = -1;
        size = n;
        s = new int[n];
    }
    void push(int x) {
        if(top == size-1) {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        s[++top] = x;
    }
    
    int pop() {
        if(top == -1) {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        int x = s[top--];
        return x;
    }
    
    int peek() {
        return s[top];
    }
    
    int returnSize() {
        return size;
    }
    
    bool empty() {
        if(top == -1) {
            return true;
        }
        return false;
    }
};

int main() {
    Stack st(5);
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
    return 0;
}