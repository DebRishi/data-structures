#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector <int> & v,int i) {
    int maxIndex = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < v.size() && v[maxIndex] < v[left]) {
        maxIndex = left;
    }
    if(right < v.size() && v[maxIndex] < v[right]) {
        maxIndex = right;
    }
    if(maxIndex != i) {
        swap(v[i],v[maxIndex]);
        maxHeapify(v,maxIndex);
    }
}

int main() {
    vector <int> v = {10,15,21,30,18,19};
    for(int i = v.size()-1 ; i >= 0 ; i--) {
        maxHeapify(v,i);
    }
    for(auto i : v) {
        cout<<i<<" ";
    }
    return 0;
}