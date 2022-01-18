#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue <int> q1;
    queue <int> q2;
    
    public:
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty()) {
            return -1;
        }
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        swap(q1,q2);
        return x;
    }
    
    int top() {
        if(q1.empty()) {
            return -1;
        }
        return q1.back();
    }
    
    int size() {
        return q1.size();
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.size()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.top()<<endl;
}