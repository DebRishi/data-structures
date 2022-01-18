#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.length();
        unordered_set<char> set;
        int ans = 0;
        int i = 0;
        int j = 0;
        while(j < n) {
            if(set.find(str[j]) == set.end()) {
                set.insert(str[j]);
                ans = max(ans,j-i+1);
                j++;
            }
            else {
                set.erase(str[i]);
                i++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcabcbb");
    return 0;
}