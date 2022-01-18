#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trapRainwater(vector <int> h) {
    stack <int> st;
    int ans = 0;
    for(int i = 0 ; i < h.size() ; i++) {
        while(!st.empty() && h[st.top()] < h[i]) {
            int cur = st.top();
            st.pop();
            if(st.empty()) {
                break; // Cannot be enclosed
            }
            int width = i - st.top() - 1;
            ans += ( min(h[i],h[st.top()]) - h[cur] ) * width;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector <int> h = {4,2,0,3,2,5};
    cout<<trapRainwater(h);
    return 0;
}