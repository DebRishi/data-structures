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
        size = n;
        q = new int[n];
    }
    
    void push(int x) {
        if(rear == size) {
            cout<<"Rear Overflow"<<endl;
            return;
        }
        q[rear++] = x;
    }
    
    int pop() {
        if(front == rear) {
            cout<<"Front Underflow"<<endl;
            return -1;
        }
        return q[front++];
    }
    
    bool empty() {
        if(front == rear) {
            return true;
        }
        return false;
    }
    
    int returnFront() {
        if(empty()) {
            return -1;
        }
        return q[front];
    }
    
    int returnRear() {
        if(empty()) {
            return -1;
        }
        return q[rear-1];
    }
    
    int returnSize() {
        return rear - front;
    }
    
    void printQueue() {
        for(int i = front ; i < rear ; i++) {
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.printQueue();
    return 0;
}