#include<iostream>
#include<vector>
using namespace std;

class NumArray {
    int seg[4*30000];
    int limit;
    
    int constructTree(vector<int>& nums,int low,int hii,int pos = 0) {
        if(low > hii)
            return 0;
        if(low == hii)
            return seg[pos] = nums[low];
        int mid = low + (hii-low)/2;
        int left = constructTree(nums,low,mid,2*pos+1);
        int right = constructTree(nums,mid+1,hii,2*pos+2);
        return seg[pos] = left+right;
    }
    
    int updateTree(int idx,int val,int low,int hii,int pos = 0) {
        if(idx < low || idx > hii)
            return 0;
        if(low == hii) {
            int diff = val - seg[pos];
            seg[pos] = val;
            return diff;
        }
        int mid = low + (hii-low)/2;
        int ldiff = updateTree(idx,val,low,mid,2*pos+1);
        int rdiff = updateTree(idx,val,mid+1,hii,2*pos+2);
        seg[pos] += ldiff + rdiff;
        return ldiff + rdiff;
    }
    
    int getSum(int llim,int rlim,int low,int hii,int pos = 0) {
        if(low > rlim || hii < llim)
            return 0;
        if(low >= llim && hii <= rlim)
            return seg[pos];
        int mid = low + (hii-low)/2;
        int lsum = getSum(llim,rlim,low,mid,2*pos+1);
        int rsum = getSum(llim,rlim,mid+1,hii,2*pos+2);
        return lsum + rsum;
    }
    
public:
    
    NumArray(vector<int>& nums) {
        constructTree(nums,0,limit = nums.size()-1);
    }
    
    void update(int idx, int val) {
        updateTree(idx,val,0,limit);
    }
    
    int sumRange(int llim, int rlim) {
        return getSum(llim,rlim,0,limit);
    }
};

int main() {
    return 0;
}