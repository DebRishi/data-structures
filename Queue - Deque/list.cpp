#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
    Node * prev;
    
    Node(int x = 0,Node * n = 0,Node * p = 0) {
        data = x;
        next = n;
        prev = p;
    }
};

class Dequeue {
    Node * front;
    Node * rear;
    int size;
    
    public :
    
    Dequeue() {
        front = 0;
        rear = 0;
        size = 0;
    }
    
    void pushFront(int x) {
        Node * n = new Node(x);
        if(!n) {
            cout<<"Heap Overflow"<<endl;
            return;
        }
        size++;
        if(front == 0) {
            front = n;
            rear = n;
            return;
        }
        n->next = front;
        front->prev = n;
        front = n;
    }
    
    void pushRear(int x) {
        Node * n = new Node(x);
        if(!n) {
            cout<<"Heap Overflow"<<endl;
            return;
        }
        size++;
        if(rear == 0) {
            front = n;
            rear = n;
            return;
        }
        n->prev = rear;
        rear->next = n;
        rear = n;
    }
    
    int popFront() {
        if(front == 0) {
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        size--;
        int x = front->data;
        Node * temp = front;
        front = front->next;
        delete(temp);
        if(front == 0) {
            rear = 0;
        }
        else {
            front->prev = 0;
        }
        return x;
    }
    
    int popRear() {
        if(rear == 0) {
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        size--;
        int x = rear->data;
        Node * temp = rear;
        rear = rear->prev;
        delete(temp);
        if(rear == 0) {
            front = 0;
        }
        else {
            rear->next = 0;
        }
        return x;
    }
    
    bool empty() {
        if(front == 0) {
            return true;
        }
        return false;
    }
    
    int returnFront() {
        if(front == 0) {
            return -1;
        }
        return front->data;
    }
    
    int returnRear() {
        if(rear == 0) {
            return -1;
        }
        return rear->data;
    }
    
    int returnSize() {
        return size;
    }
    
    void printDequeue() {
        Node * n;
        for(n = front ; n != 0 ; n=n->next) {
            cout<<n->data<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Dequeue d;
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
    cout<<"size : "<<d.returnSize()<<endl;
    cout<<d.returnFront()<<endl;
    cout<<d.returnRear()<<endl;
    cout<<d.empty()<<endl;
    d.printDequeue();
    return 0;
}