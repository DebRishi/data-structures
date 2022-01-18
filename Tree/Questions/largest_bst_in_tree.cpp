#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;

    Node(int x = 0,Node * l = 0,Node * r = 0) {
        data = x;
        left = l;
        right = r;
    }
};

struct Info {
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node * root) {
    if(root == 0) {
        return {0,INT_MAX,INT_MIN,0,true};
    }
    
    Info left = largestBSTinBT(root->left);
    Info right = largestBSTinBT(root->right);
    
    Info cur;
    cur.size = 1 + left.size + right.size;
    cur.min = min(left.min,root->data);
    cur.max = max(right.max,root->data);
    
    if(left.isBST && right.isBST && left.max < root->data && right.min > root->data) {
        cur.ans = cur.size;
        cur.isBST = true;
    } else {
        cur.ans = max(left.ans,right.ans);
        cur.isBST = false;
    }
    
    return cur;
}

int main() {
    Node * root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);
    cout<<largestBSTinBT(root).ans;
    return 0;
}