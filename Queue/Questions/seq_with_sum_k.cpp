#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int seqWithSumK(vector <int> v,int k) {
    priority_queue <int,vector <int>> maxheap;
    for(int i : v) {
        maxheap.push(i);
    }
    int sum = 0;
    int count = 0;
    while(!maxheap.empty()) {
        sum += maxheap.top();
        count++;
        maxheap.pop();
        if(sum >= k) {
            break;
        }
    }
    return count;
}

int main() {
    vector <int> v = {1,1,3,2,8};
    cout<<seqWithSumK(v,13);
    return 0;
}