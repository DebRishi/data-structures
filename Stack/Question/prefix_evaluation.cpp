#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int evalPrefix(string prefix) {
    stack <int> s;
    for(int i = prefix.length()-1 ; i >= 0 ; i--) {
        if(prefix[i] >= '0' && prefix[i] <= '9') {
            s.push(prefix[i]-'0');
        }
        else {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            switch(prefix[i]) {
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
    string prefix = "-+7*45+20";
    cout<<evalPrefix(prefix)<<endl;
    return 0;
}