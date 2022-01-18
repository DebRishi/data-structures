#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num,int k) {
        stack<char> stack;
        for(char c : num) {
            while(!stack.empty() && c < stack.top() && k > 0) {
                stack.pop();
                k--;
            }
            stack.push(c);
        }
        while(k > 0) {
            stack.pop();
            k--;
        }
        string ans = "";
        while(!stack.empty()) {
            ans += stack.top();
            stack.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while(i < ans.size() && ans[i] == '0')
            i++;
        return i == ans.size() ? "0" : ans.substr(i);
    }
};

int main() {
    string num = "14301620";
    int k = 4;
    Solution s;
    cout<<s.removeKdigits(num,k);
    return 0;
}