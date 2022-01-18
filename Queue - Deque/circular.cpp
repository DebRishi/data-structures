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
        size = n+1;
        q = new int[n+1];
    }
    
    void pushFront(int x) {
        if((size+front-1)%size == rear) {
            cout<<"Front Overflow"<<endl;
            return;
        }
        front = (size+front-1)%size;
        q[front] = x;
    }
    
    void pushRear(int x) {
        if((rear+1)%size == front) {
            cout<<"Rear Overflow"<<endl;
            return;
        }
        q[rear] = x;
        rear = (rear+1)%size;
    }
    
    int popFront() {
        if(front == rear) {
            cout<<"Front Underflow"<<endl;
            return -1;
        };
        int x = q[front];
        front = (front+1)%size;
        return x;
    }
    
    int popRear() {
        if(front == rear) {
            cout<<"Rear Underflow"<<endl;
            return -1;
        }
        rear = (size+rear-1)%size;
        return q[rear];
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
        return q[(size+rear-1)%size];
    }
    
    int returnSize() {
        if(rear >= front) {
            return rear-front;
        }
        else {
            return size+(rear-front);
        }
    }
    
    void printDequeue() {
        if(empty()) {
            cout<<"Empty Queue"<<endl;
        }
        int x = front;
        while(x != rear) {
            cout<<q[x]<<" ";
            x = (x+1)%size;
        }
        cout<<endl;
    }
};

int main() {
    Dequeue d(5);
    d.pushFront(0);
    d.pushRear(1);
    d.pushRear(2);
    d.pushRear(3);
    d.pushRear(4);
    d.pushRear(5);
    d.printDequeue();
    d.popFront();
    d.popRear();
    d.popFront();
    d.popRear();
    d.popFront();
    d.popRear();
    cout<<"size : "<<d.returnSize()<<endl;
    cout<<d.returnFront()<<endl;
    cout<<d.returnRear()<<endl;
    cout<<d.empty()<<endl;
    d.printDequeue();
    return 0;
}