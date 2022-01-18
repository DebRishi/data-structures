#include <iostream>
#include <vector>
#include <stack>

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

void printZigZag(Node * root) {
    if(root == 0) {
        return;
    }

    vector <int> result;
    stack <Node *> currLevel;
    stack <Node *> nextLevel;
    bool leftToRight = true;
    currLevel.push(root);

    while(!currLevel.empty()) {
        Node * node = currLevel.top();
        result.push_back(node->data);
        currLevel.pop();
        
        if(leftToRight) {
            if(node->left) {
                nextLevel.push(node->left);
            }
            if(node->right) {
                nextLevel.push(node->right);
            }
        }
        else {
            if(node->right) {
                nextLevel.push(node->right);
            }
            if(node->left) {
                nextLevel.push(node->left);
            }
        }

        if(currLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currLevel,nextLevel);
        }
    }

    for(auto i : result) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {
    Node * root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);
    printZigZag(root);
    return 0;
}