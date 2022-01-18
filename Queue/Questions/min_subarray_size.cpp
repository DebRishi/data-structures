#include <iostream>

using namespace std;

int minSubArrayLen(int arr[],int n,int limit) {
    int ans = n+1;
    int sum = 0;
    int start = 0;
    int end = 0;
    while(end < n) {
        sum += arr[end++];
        while(sum >= limit) {
            if(ans > end - start) {
                ans = end - start;
            }
            sum -= arr[start++];
        }
    }
    if(ans == n+1) {
        return 0;
    }
    return ans;
}

int main() {
    int arr[] = {1,2,3,4,5};
    cout<<minSubArrayLen(arr,5,11);
}