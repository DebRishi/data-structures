#include<iostream>
#include<vector>
using namespace std;

// LEETCODE 307
class NumArray {

    struct SegmentTreeNode {
        int sum;
        int low;
        int hii;
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        SegmentTreeNode(int s,int l,int h,SegmentTreeNode* left = 0,SegmentTreeNode* right = 0) {
            sum = s;
            low = l;
            hii = h;
            this->left = left;
            this->right = right;
        }
    };
    
    SegmentTreeNode* root;
    
    SegmentTreeNode* constructTree(vector<int>& nums,int low,int hii) {
        if(low > hii)
            return 0;
        if(low == hii)
            return new SegmentTreeNode(nums[low],low,hii);
        int mid = low + (hii-low)/2;
        SegmentTreeNode* left = constructTree(nums,low,mid);
        SegmentTreeNode* right = constructTree(nums,mid+1,hii);
        return new SegmentTreeNode(left->sum + right->sum,low,hii,left,right);
    }
    
    int getSum(SegmentTreeNode* root,int llim,int rlim) {
        if(root->low > rlim || root->hii < llim)
            return 0;
        if(root->low >= llim && root->hii <= rlim)
            return root->sum;
        int lsum = getSum(root->left,llim,rlim);
        int rsum = getSum(root->right,llim,rlim);
        return lsum + rsum;
    }
    
    int updateTree(SegmentTreeNode* root,int pos,int val) {
        if(pos < root->low || pos > root->hii)
            return 0;
        if(root->low == root->hii) {
            int diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int ldiff = updateTree(root->left,pos,val);
        int rdiff = updateTree(root->right,pos,val);
        root->sum += ldiff + rdiff;
        return ldiff + rdiff;
    }

  public:
    
    NumArray(vector<int>& nums) {
        root = constructTree(nums,0,nums.size()-1);
    }
    
    int sumRange(int left, int right) {
        return getSum(root,left,right);
    }
    
    void update(int pos, int val) {
        updateTree(root,pos,val);
    }
};

int main() {
    return 0;
}