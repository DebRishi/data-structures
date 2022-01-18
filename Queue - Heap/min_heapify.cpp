#include <iostream>
#include <vector>

using namespace std;

void minHeapify(vector <int> & v,int i) {
    int minIndex = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < v.size() && v[minIndex] > v[left]) {
        minIndex = left;
    }
    if(right < v.size() && v[minIndex] > v[right]) {
        minIndex = right;
    }
    if(minIndex != i) {
        swap(v[i],v[minIndex]);
        minHeapify(v,minIndex);
    }
}

int main() {
    vector <int> v = {30,18,21,15,10,19};
    for(int i = v.size()-1 ; i >= 0 ; i--) {
        minHeapify(v,i);
    }
    for(auto i : v) {
        cout<<i<<" ";
    }
    return 0;
}