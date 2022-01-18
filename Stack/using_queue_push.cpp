#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue <int> q1;
    queue <int> q2;
    
    public:
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        if(q1.empty()) {
            return -1;
        }
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        if(q1.empty()) {
            return -1;
        }
        return q1.front();
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