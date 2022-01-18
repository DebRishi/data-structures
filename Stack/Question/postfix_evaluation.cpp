#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int evalPostfix(string postfix) {
    stack <int> s;
    for(int i = 0 ; i < postfix.length() ; i++) {
        if(postfix[i] >= '0' && postfix[i] <= '9') {
            s.push(postfix[i]-'0');
        }
        else {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            
            switch(postfix[i]) {
                case '+' : s.push(a+b); break;
                case '-' : s.push(a-b); break;
                case '*' : s.push(a*b); break;
                case '/' : s.push(a/b); break;
                case '^' : s.push(pow(a,b)); break;
                default : return -1;
            }
        }
    }
    return s.top();
}

int main() {
    string postfix = "46+2/5*7+";
    cout<<evalPostfix(postfix)<<endl;
    return 0;
}