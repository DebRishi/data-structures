#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
    
    Node(int x = 0,Node * n = 0) {
        data = x;
        next = n;
    }
};

class Queue {
    Node * front;
    Node * rear;
    int size;
    
    public :
    
    Queue() {
        front = 0;
        rear = 0;
        size = 0;
    }
    
    void push(int x) {
        Node * n = new Node(x);
        if(!n) {
            cout<<"Heap Overflow"<<endl;
            return;
        }
        size++;
        if(front == 0) {
            front = rear = n;
        }
        rear->next = n;
        rear = n;
    }
    
    int pop() {
        if(front == 0) {
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        int x = front->data;
        Node * temp = front;
        front = front->next;
        delete(temp);
        size--;
        if(front == 0) {
            rear = 0;
        }
        return x;
    }
    
    bool empty() {
        if(front == 0) {
            return true;
        }
        return false;
    }
    
    int returnSize() {
        return size;
    }
    
    int returnFront() {
        if(empty()) {
            return -1;
        }
        return front->data;
    }
    
    int returnRear() {
        if(empty()) {
            return -1;
        }
        return rear->data;
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.pop();
    q.pop();
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<q.returnFront()<<endl;
    cout<<q.returnRear()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;
    cout<<q.returnFront()<<endl;
    cout<<q.returnRear()<<endl;
    return 0;
}