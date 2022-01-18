#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue <int,vector <int>> maxheap;
priority_queue <int,vector <int>,greater <int>> minheap;

void insert(int num) {
    if(maxheap.size() == minheap.size()) {
        if(maxheap.size() == 0) {
            minheap.push(num);
            return;
        }
        if(num > maxheap.top()) {
            minheap.push(num);
        }
        else {
            maxheap.push(num);
        }
    }
    else {
        if(maxheap.size() > minheap.size()) {
            if(num > maxheap.top()) {
                minheap.push(num);
            }
            else {
                int temp = maxheap.top();
                maxheap.pop();
                maxheap.push(num);
                minheap.push(temp);
            }
        }
        else {
            if(num < minheap.top()) {
                maxheap.push(num);
            }
            else {
                int temp = minheap.top();
                minheap.pop();
                minheap.push(num);
                maxheap.push(temp);
            }
        }
    }
}

double getMedian() {
    if(maxheap.size() == minheap.size()) {
        return (maxheap.top() + minheap.top())/2.0;
    }
    else {
        if(maxheap.size() > minheap.size()) {
            return maxheap.top();
        }
        else {
            return minheap.top();
        }
    }
}

int main() {
    int arr[] = {10,15,21,30,18,19};
    for(int i : arr) {
        insert(i);
        cout<<getMedian()<<" ";
    }
    cout<<endl;
    return 0;
}