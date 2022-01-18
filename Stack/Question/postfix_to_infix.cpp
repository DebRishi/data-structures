#include <iostream>
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

string postfixToInfix(string postfix) {
    stack <string> s;
    for(int i = 0 ; i < postfix.length() ; i++) {
        if(opCheck(postfix[i])) {
            string b = s.top();
            s.pop();
            string a = s.top();
            s.pop();
            s.push('('+a+postfix[i]+b+')');
        }
        else {
            s.push(postfix.substr(i,1));
        }
    }
    return s.top();
}

int main() {
    string postfix = "ab+cd-/";
    cout<<postfixToInfix(postfix)<<endl;
    return 0;
}