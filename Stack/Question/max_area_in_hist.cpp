#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maxArea(vector <int> h) {
    h.push_back(-1);
    stack <int> s;
    int max_area = 0;
    int i = 0;
    while(i < h.size()) {
        while(!s.empty() && h[i] < h[s.top()]) {
            int t = h[s.top()];
            s.pop();
            if(s.empty()) {
                max_area = max(max_area,t*i);
            }
            else {
                int l = i - s.top() - 1;
                max_area = max(max_area,t*l);
            }
        }
        s.push(i);
        i++;
    }
    return max_area;
}

int main() {
    vector <int> h = {2,1,5,6,2,3};
    cout<<maxArea(h)<<endl;
}