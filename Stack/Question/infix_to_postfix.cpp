#include <iostream>
#include <stack>

using namespace std;

class Solution {
    public:
    
    int checkOp(char c) {
        if(c == '^')
            return 3;
        else if(c == '*' || c == '/')
            return 2;
        else if(c == '+' || c == '-')
            return 1;
        else
            return 0;
    }
    
    string infixToPostfix(string exp) {
        string postfix = "";
        stack<char> stack;
        for(auto c : exp) {
            if(c == '(')
                stack.push('(');
            else if(c == ')') {
                while(stack.top() != '(') {
                    postfix += stack.top();
                    stack.pop();
                }
                stack.pop();
            }
            else if(checkOp(c)) {
                while(!stack.empty() && checkOp(c) <= checkOp(stack.top())) {
                    postfix += stack.top();
                    stack.pop();
                }
                stack.push(c);
            }
            else
                postfix += c;
        }
        while(!stack.empty()) {
            postfix += stack.top();
            stack.pop();
        }
        return postfix;
    }
};

int main() {
    Solution s;
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout<<s.infixToPostfix(infix)<<endl;
    return 0;
}