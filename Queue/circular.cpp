#include <iostream>

using namespace std;

class Queue {
    int * q;
    int front;
    int rear;
    int size;
    
    public :
    
    Queue(int n = 0) {
        front = 0;
        rear = 0;
        size = n+1;
        q = new int[n+1];
    }
    
    void push(int x) {
        if((rear+1)%size == front) {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        rear = (rear+1)%size;
        q[rear] = x;
    }
    
    int pop() {
        if(front == rear) {
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        front = (front+1)%size;
        return q[front];
    }
    
    bool empty() {
        if(rear == front) {
            return true;
        }
        return false;
    }
    
    int returnSize() {
        return size-1;
    }
    
    int returnFront() {
        if(empty()) {
            return -1;
        }
        return q[front+1];
    }
    
    int returnRear() {
        if(empty()) {
            return -1;
        }
        return q[rear];
    }
};

int main() {
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<q.returnFront()<<endl;
    cout<<q.returnRear()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.returnFront()<<endl;
    cout<<q.returnRear()<<endl;
    cout<<q.empty()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    return 0;
}