#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector <int> maxSlidingWindow(vector <int> num, int k) {
    vector <int> ans;
    multiset <int,greater <int>> max;
    for(int i = 0 ; i < k ; i++) {
        max.insert(num[i]);
    }
    ans.push_back(*max.begin());
    for(int i = k ; i < num.size() ; i++) {
        max.insert(num[i]);
        max.erase(max.find(num[i-k]));
        ans.push_back(*max.begin());
    }
    return ans;
}

int main() {
    vector <int> v = {1,3,-1,-3,5,3,6,7};
    for(auto i : maxSlidingWindow(v,3)) {
        cout<<i<<" ";
    }
    return 0;
}