#include <iostream>

using namespace std;

class Dequeue {
    int * q;
    int front;
    int rear;
    int size;
    
    public :
    
    Dequeue(int n = 0) {
        front = 0;
        rear = 0;
        size = n;
        q = new int[n];
    }
    
    void pushFront(int x) {
        if(front-1 == -1) {
            cout<<"Front Overflow"<<endl;
            return;
        }        
        q[--front] = x;
    }
    
    void pushRear(int x) {
        if(rear == size) {
            cout<<"Rear Overflow"<<endl;
            return;
        }
        q[rear++] = x;
    }
    
    int popFront() {
        if(front == rear) {
            cout<<"Front Underflow"<<endl;
            return -1;
        }
        return q[front++];
    }
    
    int popRear() {
        if(front == rear) {
            cout<<"Rear Underflow"<<endl;
            return -1;
        }
        return q[--rear];
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
    
    void printDequeue() {
        for(int i = front ; i < rear ; i++) {
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Dequeue d(5);
    d.pushRear(1);
    d.pushRear(2);
    d.pushRear(3);
    d.pushRear(4);
    d.pushRear(5);
    d.pushRear(6);
    d.popFront();
    d.pushFront(0);
    d.printDequeue();
}