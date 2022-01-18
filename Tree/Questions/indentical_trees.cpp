#include <iostream>

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

bool checkIdentical(Node * root,Node * clone) {
    if(root == 0 && clone == 0) {
        return true;
    }

    if(!root || !clone) {
        return false;
    }
    
    if(root->data == clone->data) {
        if(checkIdentical(root->left,clone->left) && checkIdentical(root->right,clone->right)) {
            return true;
        }
    }

    return false;
}

int main() {
    Node * root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);

    Node * clone = new Node(12);
    clone->left = new Node(9);
    clone->right = new Node(15);
    clone->left->left = new Node(5);
    clone->left->right = new Node(10);

    cout<<checkIdentical(root,clone);
}