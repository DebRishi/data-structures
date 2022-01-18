#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#define pii pair <int,int>

vector <int> mergeSortedArrays(vector <vector <int>> v) {
    priority_queue <pii,vector <pii>,greater <pii>> minheap; // initialize min heap;
    vector <int> index (v.size(),0); // Keeps Track of current indices
    vector <int> ans;

    for(int i = 0 ; i < v.size() ; i++) {
        minheap.push({v[i][0],i});
    }

    while(!minheap.empty()) {
        pii x = minheap.top();
        minheap.pop();
        ans.push_back(x.first);

        if(index[x.second]+1 < v[x.second].size()) {
            index[x.second]++;
            minheap.push({v[x.second][index[x.second]],x.second});
        }
    }
    
    return ans;
}

int main() {
    vector <vector <int>> v = {
        {1,4,7},
        {3,5},
        {2,6,7}
    };
    vector <int> r = mergeSortedArrays(v);
    for(auto i : r) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}