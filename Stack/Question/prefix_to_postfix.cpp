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

string prefixToPostfix(string prefix) {
    stack <string> s;
    for(int i = prefix.length()-1 ; i >= 0 ; i--) {
        if(opCheck(prefix[i])) {
            string a = s.top();
            s.pop();
            string b = s.top();
            s.pop();
            s.push(a+b+prefix[i]);
        }
        else {
            s.push(prefix.substr(i,1));
        }
    }
    return s.top();
}

int main() {
    string prefix = "/+ab-cd";
    cout<<prefixToPostfix(prefix)<<endl;
    return 0;
}