#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

int opCheck(char ch) {
    if(ch == '^'){
        return 3;
    }
    else if(ch == '/' || ch == '*') {
        return 2;
    }
    else if(ch == '+' || ch == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

string infixToPrefix(string infix) {
    reverse(infix.begin(),infix.end());
    string prefix = "";
    stack <char> s;
    for(int i = 0 ; i < infix.length() ; i++) {
        if(infix[i] == ')') {
            s.push(')');
        }
        else if(infix[i] == '(') {
            while(s.top() != ')') {
                prefix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if(opCheck(infix[i])) {
            while(!s.empty() && opCheck(infix[i])<opCheck(s.top())) {
                prefix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
        else {
            prefix += infix[i];
        }
    }
    while(!s.empty()) {
        prefix += s.top();
        s.pop();
    }
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

int main() {
    string infix = "(a+b^c)*d+e^f";
    cout<<infixToPrefix(infix)<<endl;
    return 0;
}