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

void calcPointers(Node * root,Node ** first,Node ** mid,Node ** last,Node ** prev) {
    if(root == 0) {
        return;
    }
    calcPointers(root->left,first,mid,last,prev);
    if(*prev && root->data < (*prev)->data) {
        if(!*first) {
            *first = *prev;
            *mid = root;
        }
        else {
            *last = root;
        }
    }
    *prev = root;
    calcPointers(root->right,first,mid,last,prev);
}

void restoreBST(Node * root) {
    Node * first = 0;
    Node * mid = 0;
    Node * last = 0;
    Node * prev = 0;
    calcPointers(root,&first,&mid,&last,&prev);

    if(first && last) {
        swap(first->data,last->data);
    }
    else {
        swap(first->data,mid->data);
    }
}

void print(Node * root) {
    if(root == 0) {
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main() {
    Node *root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);
    print(root);
    cout<<endl;
    restoreBST(root);
    print(root);
    return 0;
}