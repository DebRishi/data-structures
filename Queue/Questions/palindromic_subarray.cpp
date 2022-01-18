#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPalindrome(int num) {
    int rev = 0;
    int n = num;
    while(n > 0) {
        rev = rev*10 + n%10;
        n = n/10;
    }
    if (num == rev) {
        return true;
    }
    else {
        return false;
    }
}

int findPalindromicSubArray(vector <int> arr,int k) {
    int num = 0;
    for(int i = 0 ; i < k ; i++) {
        num = num*10 + arr[i];
    }
    if(isPalindrome(num)) {
        return 0;
    }
    for(int i = k ; i < arr.size() ; i++) {
        num = (num % (int)pow(10,k-1))*10 + arr[i];
        if(isPalindrome(num)) {
            return i-k+1;
        }
    }
    return -1;
}

int main() {
    vector <int> v = {2,3,5,1,1,5};
    int k = 4;
    int ans = findPalindromicSubArray(v,k);
    if(ans == -1) {
        cout<<"Palindrome Doesn't exist";
    }
    else {
        for(int i = ans ; i < ans+k ; i++) {
            cout<<v[i]<<" ";
        }
    }
    return 0;
}