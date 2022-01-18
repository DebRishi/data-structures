#include <iostream>
#include <vector>
using namespace std;

pair <int,int> divisibleSubArray(vector <int> arr,int k) {
    pair <int,int> ans;
    int sum = 0;
    for(int i = 0 ; i < k ; i++) {
        sum += arr[i];
    }
    if(sum%3 == 0) {
        ans = make_pair(0,k-1);
        return ans;
    }
    for(int i = k ; i < arr.size() ; i++) {
        sum = sum + arr[i] - arr[i-k];
        if(sum%3 == 0) {
            ans = make_pair(i-k+1,i);
            return ans;
        }
    }
    ans = make_pair(-1,-1);
    return ans;
}

int main() {
    vector <int> v = {84,23,45,12,56,82};
    pair <int,int> p = divisibleSubArray(v,3);
    for(int i = p.first ; i <= p.second ; i++) {
        cout<<v[i]<<" ";
    }
    return 0;
}